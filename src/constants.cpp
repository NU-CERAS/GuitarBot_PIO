#include "constants.h"
using namespace std;

// Solenoid pin vectors, must be in consecutive order from lowest to highest solenoid

// THESE ARE ARBITRARY VALUES, MUST BE REPLACED WITH ACTUAL PIN NUMBERS 
std::vector<int> string1PinVec = {0,1,2,3};
std::vector<int> string2PinVec = {0,1,2,3};
std::vector<int> string3PinVec = {};
std::vector<int> string4PinVec = {};
std::vector<int> string5PinVec = {};
std::vector<int> string6PinVec = {};

const std::array<std::vector<int>, 2> stringPinVecs = {
    string1PinVec, 
    string2PinVec};
/*
    string3PinVec, 
    string4PinVec, 
    string5PinVec, 
    string6PinVec
};
*/
// MIDI VALUES
const int string1Midi = 20;
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

// Begin Servo constants

// Servo positions
// These arrays define the high and low positions for each of the servos controlling the guitar strumming mechanism.
// Arbitrary values, must be tuned for actual hardware
int highPos[NUM_SERVOS] = {80};
int lowPos[NUM_SERVOS] = {20};
// Stores the target position each servo should move to based on incoming MIDI velocity
// initialized to 0 for all servos
int servoValues[NUM_SERVOS] = {0};



// 	Tracks whether each servo is currently in an active "hitting" state
bool servoAction[NUM_SERVOS] = {false};

// Servo objects for controlling each servo motor
Servo servos[NUM_SERVOS];

// Track current servo positions, false = lowPos, true = highPos
bool currentServoPositions[NUM_SERVOS] = {false};
int servoPins[NUM_SERVOS] = {7};


