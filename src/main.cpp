#include <Arduino.h>
#include <Adafruit_MCP23X17.h>
#include "midihandler.h"
#include "constants.h"
#include <iostream>
// put function declarations here:

void initializeActiveSolenoidMap(bool &activeString, Adafruit_MCP23X17 &mcp);
void initializeMidiToPinMap(std::vector<int> pinVec, std::map<int, int> &midiToPinMap, int baseMidiValue);

// Assume we have 6 MCP23008 for 6 strings
// Adjust as needed
const int numMCPs = 6;

Adafruit_MCP23X17 stringMCPs[numMCPs];

uint8_t mcpAddresses[numMCPs] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25}; // tbd


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("setup ran"); 

  // Initialize each multiplexer
  // Update addresses for actual board configuration
  
  for (int i = 0; i < numMCPs; i++) {
      stringMCPs[i].begin_I2C(mcpAddresses[i]);
  }

  // Initialize active solenoid maps
  for (size_t i = 0; i < 6; i++) {
      initializeActiveSolenoidMap(activeStringMaps[i], stringMCPs[i]);
  }

  // Initialize midi to pin assignment maps
  for (size_t i = 0; i < MidiToPinMaps.size(); i++) {
      initializeMidiToPinMap(stringPinVec, MidiToPinMaps[i], stringMidiValues[i]);
  }

  // Set pmos and nmos to inactive state
  for (size_t i = 0; i < numMCPs; i++) {
      for (int pin = 0; pin < 4; pin++) {
          stringMCPs[i].digitalWrite(pin, HIGH);
      }
      for (int pin = 4; pin < 8; pin++) {
          stringMCPs[i].digitalWrite(pin, LOW);
      }
  }
  Serial.println("initialized mcps, solenoid maps, midi to pin assignment maps");

}

void loop() {
  
    readAndProcessMIDI();
  
    // Serial.println("Low E Size:" + String(MidiToPinMaps[0].size()));
    // Serial.println("A Size:" + String(MidiToPinMaps[1].size()));
    // Serial.println("D Size:" + String(MidiToPinMaps[2].size()));
    // Serial.println("G Size:" + String(MidiToPinMaps[3].size()));
    // Serial.println("B Size:" + String(MidiToPinMaps[4].size()));
    // Serial.println("High E Size:" + String(MidiToPinMaps[5].size()));
  
}

// function definitions
// May need to be rewritten to accomodate pmos and nmos control
// initializes the active solenoid map for a string
void initializeActiveSolenoidMap(bool &activeString, Adafruit_MCP23X17 &mcp) {
    activeString = false;
    for (int pin = 0; pin < 8; pin++) {
        mcp.pinMode(pin, OUTPUT);
    }
}

// initializes the midi to pin assignment map for a string
void initializeMidiToPinMap(std::vector<int> pinVec, std::map<int, int> &midiToPinMap, int baseMidiValue) {
  for (size_t i = 0; i < (pinVec.size() + 1); i++) {
    if (i == 0) {
        midiToPinMap[baseMidiValue] = -1;
    }
    else {
        midiToPinMap[baseMidiValue + i] = pinVec[i-1];
    }
  }
}

