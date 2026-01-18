#pragma once
#include <map>
#include <vector>
// using namespace std;

// Pin vector
extern std::vector<int> stringPinVec;


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



