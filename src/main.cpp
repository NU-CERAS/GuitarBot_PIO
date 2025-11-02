#include <Arduino.h>
#include <Adafruit_MCP23X08.h>
#include "midihandler.h"
#include "constants.h"
#include <iostream>
// put function declarations here:

void initializeActiveSolenoidMap(std::vector<int> pinVec, std::map<int, bool> &activeMap, Adafruit_MCP23X08 &mcp);
void initializeMidiToPinMap(std::vector<int> pinVec, std::map<int, int> &midiToPinMap, int baseMidiValue);

// Assume we have 6 MCP23008 for 6 strings
// Adjust as needed
const int numMCPs = 6;

Adafruit_MCP23X08 stringMCPs[numMCPs];

uint8_t mcpAddresses[numMCPs] = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Initialize each multiplexer
  // Update addresses for actual board configuration
  for (int i = 0; i < numMCPs; i++) {
      stringMCPs[i].begin_I2C(mcpAddresses[i]);
  }

  // Initialize active solenoid maps
  for (size_t i = 0; i < stringPinVecs.size(); i++) {
      initializeActiveSolenoidMap(stringPinVecs[i], activeStringMaps[i], stringMCPs[i]);
  }

  // Initialize midi to pin assignment maps
  for (size_t i = 0; i < MidiToPinMaps.size(); i++) {
      initializeMidiToPinMap(stringPinVecs[i], MidiToPinMaps[i], stringMidiValues[i]);
  }
}

void loop() {
  
  //printMIDIMessage();
  readAndProcessMIDI();
  /*
  Serial.println("Low E Size:" + String(string1MidiToPin.size()));
  Serial.println("A Size:" + String(string2MidiToPin.size()));
  Serial.println("D Size:" + String(string3MidiToPin.size()));
  Serial.println("G Size:" + String(string4MidiToPin.size()));
  Serial.println("B Size:" + String(string5MidiToPin.size()));
  Serial.println("High E Size:" + String(string6MidiToPin.size()));
  */
}

// put function definitions here:

// initializes the active solenoid map for a string
void initializeActiveSolenoidMap(std::vector<int> pinVec, std::map<int, bool> &activeMap, Adafruit_MCP23X08 &mcp) {
    for (int pin : pinVec) {
        activeMap[pin] = false;
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

