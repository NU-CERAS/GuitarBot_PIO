#pragma once
#include <map>
#include <vector>
#include <Adafruit_MCP23X08.h>

// using namespace std;

// Pin vectors
extern std::vector<int> string1PinVec;
extern std::vector<int> string2PinVec;
extern std::vector<int> string3PinVec;
extern std::vector<int> string4PinVec;
extern std::vector<int> string5PinVec;
extern std::vector<int> string6PinVec;


extern const std::array<std::vector<int>, 6> stringPinVecs;


extern std::array<Adafruit_MCP23X08, 2> testMCPs;
/*
MIDI VALUES for each string
*/
extern const int string1Midi;
extern const int string2Midi;
extern const int string3Midi;
extern const int string4Midi;
extern const int string5Midi;
extern const int string6Midi;

extern const std::array<int, 6> stringMidiValues;

// Active solenoids, key is pin number, value is active state (bool)
// Change to bool?
extern bool activeString1;
extern bool activeString2;
extern bool activeString3;
extern bool activeString4;
extern bool activeString5;
extern bool activeString6;

extern std::array<bool, 6> activeStringMaps;


// Key is midi value, value is pin number
extern std::map<int, int> string1MidiToPin;
extern std::map<int, int> string2MidiToPin;
extern std::map<int, int> string3MidiToPin;
extern std::map<int, int> string4MidiToPin;
extern std::map<int, int> string5MidiToPin;
extern std::map<int, int> string6MidiToPin;

extern std::array<std::map<int, int>, 6> MidiToPinMaps;



