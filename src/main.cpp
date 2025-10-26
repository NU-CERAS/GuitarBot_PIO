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
Adafruit_MCP23X08 string1MCP;
Adafruit_MCP23X08 string2MCP;
Adafruit_MCP23X08 string3MCP;
Adafruit_MCP23X08 string4MCP;
Adafruit_MCP23X08 string5MCP;
Adafruit_MCP23X08 string6MCP;

std::array<Adafruit_MCP23X08, 6> stringMCPs = {
    string1MCP,
    string2MCP,
    string3MCP,
    string4MCP,
    string5MCP,
    string6MCP
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Initialize each multiplexer
  // Update addresses for actual board configuration
  string1MCP.begin_I2C(0x20);
  string2MCP.begin_I2C(0x21);
  string3MCP.begin_I2C(0x22);
  string4MCP.begin_I2C(0x23);
  string5MCP.begin_I2C(0x24);
  string6MCP.begin_I2C(0x25);

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
  Serial.println("Low E Size:" + String(string1MidiToPin.size()));
  Serial.println("A Size:" + String(string2MidiToPin.size()));
  Serial.println("D Size:" + String(string3MidiToPin.size()));
  Serial.println("G Size:" + String(string4MidiToPin.size()));
  Serial.println("B Size:" + String(string5MidiToPin.size()));
  Serial.println("High E Size:" + String(string6MidiToPin.size()));
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

