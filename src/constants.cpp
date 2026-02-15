#include "constants.h"
using namespace std;

// Solenoid pin vectors, must be in consecutive order from lowest to highest solenoid

// THESE ARE ARBITRARY VALUES, MUST BE REPLACED WITH ACTUAL PIN NUMBERS 
std::vector<int> string1PinVec = {0,1,2,3,4,5,6,7};
std::vector<int> string2PinVec = {8,9,10,11,12,13,14,15}; // should start at 8
std::vector<int> string3PinVec = {};
std::vector<int> string4PinVec = {};
std::vector<int> string5PinVec = {};
std::vector<int> string6PinVec = {};

const std::array<std::vector<int>, 6> stringPinVecs = {
    string1PinVec, 
    string2PinVec, 
    string3PinVec, 
    string4PinVec, 
    string5PinVec, 
    string6PinVec
};

std::array<Adafruit_MCP23X08, 2> testMCPs = {
    Adafruit_MCP23X08(),
    Adafruit_MCP23X08()
};

// MIDI VALUES
const int string1Midi = 40;
const int string2Midi = 45;
const int string3Midi = 50;
const int string4Midi = 55;
const int string5Midi = 59;
const int string6Midi = 64;

const std::array<int, 6> stringMidiValues = {
    string1Midi,
    string2Midi,
    string3Midi,
    string4Midi,
    string5Midi,
    string6Midi
};


// Active solenoid vectors {pin number : active bool}
bool activeString1 = false;
bool activeString2 = false;
bool activeString3 = false;
bool activeString4 = false;
bool activeString5 = false;
bool activeString6 = false;

std::array<bool, 6> activeStringMaps = {
    activeString1,
    activeString2,
    activeString3,
    activeString4,
    activeString5,
    activeString6
};

// Pin assignments {midi : pin number}
std::map<int, int> string1MidiToPin = {{16,0},{17,1},{18,2},{19,3}};
std::map<int, int> string2MidiToPin = {{24,0},{25,1},{26,2},{27,3}}; // should start at 45
std::map<int, int> string3MidiToPin = {};
std::map<int, int> string4MidiToPin = {};
std::map<int, int> string5MidiToPin = {};
std::map<int, int> string6MidiToPin = {};

std::array<std::map<int, int>, 6> MidiToPinMaps = {
    string1MidiToPin,
    string2MidiToPin,
    string3MidiToPin,
    string4MidiToPin,
    string5MidiToPin,
    string6MidiToPin
};


