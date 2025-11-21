#include <Arduino.h>
#include "core_pins.h"
#include <Adafruit_MCP23X17.h>
#include "midihandler.h"
#include "constants.h"
#include "solenoid_events.h"
#include "solenoid-control.h"
#include <iostream>

#include <FreeRTOS.h>
#include <task.h>

// -------------------- FUNCTION DECLARATIONS --------------------

void initializeActiveSolenoidMap(std::vector<int> pinVec, bool &activeString, Adafruit_MCP23X17 &mcp);
void initializeMidiToPinMap(std::vector<int> pinVec, std::map<int, int> &midiToPinMap, int baseMidiValue);

// -------------------- GLOBALS --------------------

const int numMCPs = 6;
Adafruit_MCP23X17 stringMCPs[numMCPs];
uint8_t mcpAddresses[numMCPs] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25};

QueueHandle_t solenoidQueue; // RTOS Queue for solenoid events


// -------------------- FREERTOS TASK --------------------

void TaskMIDI(void* pvParams) {
    SolenoidEvent e;
    while(true) {
        // Process all available MIDI messages
        while(readAndProcessMIDI(&e)) {
            xQueueSend(solenoidQueue, &e, 0);
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

void TaskSolenoids(void* pvParams) {
    SolenoidEvent event;
    while(true) {
        if(xQueueReceive(solenoidQueue, &event, pdMS_TO_TICKS(1))) {
            int stringIndex = event.stringIndex;
            int pin = event.pin;

            if(event.on) solenoidOn(pin, stringIndex, stringMCPs[stringIndex]);
            else solenoidOff(pin, stringIndex, stringMCPs[stringIndex]);
        }
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

// -------------------- SETUP --------------------

void setup() {
    Serial.begin(9600);

    // Initialize MCP expanders
    for (int i = 0; i < numMCPs; i++) {
        stringMCPs[i].begin_I2C(mcpAddresses[i]);
    }

    // Initialize solenoid maps
    for (size_t i = 0; i < stringPinVecs.size(); i++) {
        initializeActiveSolenoidMap(stringPinVecs[i], activeStringMaps[i], stringMCPs[i]);
    }

    // Initialize MIDI→Pin assignments
    for (size_t i = 0; i < MidiToPinMaps.size(); i++) {
        initializeMidiToPinMap(stringPinVecs[i], MidiToPinMaps[i], stringMidiValues[i]);
    }

    // ---- Create FreeRTOS Tasks ----
    xTaskCreate(
        TaskMIDI,         // task function
        "MIDI Task",      // name
        4096,             // stack size (Teensy needs plenty)
        NULL,             // parameter
        1,                // priority
        NULL              // task handle
    );
    // Create task for Solenoids**

    // Start FreeRTOS
    vTaskStartScheduler();
}

// -------------------- LOOP (Unused) --------------------

void loop() {
    // Empty — FreeRTOS controls execution now
}

// -------------------- FUNCTION DEFINITIONS --------------------

void initializeActiveSolenoidMap(std::vector<int> pinVec, bool &activeString, Adafruit_MCP23X17 &mcp) {
    activeString = false;
    for (int pin : pinVec) {
        mcp.pinMode(pin, 0x01);  // OUTPUT
    }
}

void initializeMidiToPinMap(std::vector<int> pinVec, std::map<int, int> &midiToPinMap, int baseMidiValue) {
    for (size_t i = 0; i < (pinVec.size() + 1); i++) {
        if (i == 0) {
            midiToPinMap[baseMidiValue] = -1;
        } else {
            midiToPinMap[baseMidiValue + i] = pinVec[i - 1];
        }
    }
}

