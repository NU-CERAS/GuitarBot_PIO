#pragma once
#include <map>
#include <vector>
// using namespace std;
// Number of solenoids per string
extern const int string1Sols;
extern const int string2Sols;
extern const int string3Sols;
extern const int string4Sols;
extern const int string5Sols;
extern const int string6Sols;

// Pin vectors
extern std::vector<int> string1PinVec;
extern std::vector<int> string2PinVec;
extern std::vector<int> string3PinVec;
extern std::vector<int> string4PinVec;
extern std::vector<int> string5PinVec;
extern std::vector<int> string6PinVec;


extern const std::array<std::vector<int>, 6> stringPinVecs;
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
extern std::map<int, bool> activeString1;
extern std::map<int, bool> activeString2;
extern std::map<int, bool> activeString3;
extern std::map<int, bool> activeString4;
extern std::map<int, bool> activeString5;
extern std::map<int, bool> activeString6;

extern std::array<std::map<int, bool>, 6> activeStringMaps;


// Key is midi value, value is pin number
extern std::map<int, int> string1MidiToPin;
extern std::map<int, int> string2MidiToPin;
extern std::map<int, int> string3MidiToPin;
extern std::map<int, int> string4MidiToPin;
extern std::map<int, int> string5MidiToPin;
extern std::map<int, int> string6MidiToPin;

extern std::array<std::map<int, int>, 6> MidiToPinMaps;



