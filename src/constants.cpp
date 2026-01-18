#include "constants.h"
using namespace std;

// Solenoid pin vectors, must be in consecutive order from lowest to highest solenoid
std::vector<int> stringPinVec = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

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
std::map<int, int> string1MidiToPin = {};
std::map<int, int> string2MidiToPin = {};
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


