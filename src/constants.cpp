#include "constants.h"
using namespace std;

// Number of solenoids per string
// 5 is arbitrary
const int lowESols = 3;
const int aSols = 3;   
const int dSols = 3;
const int gSols = 3;
const int bSols = 3;
const int highESols = 3;

// Pin vectors, MUST be in consecutive order from lowest to highest solenoid
std::vector<int> lowEPinVec = {1,2,3};
std::vector<int> aPinVec = {4,5,6};
std::vector<int> dPinVec = {7,8,9};
std::vector<int> gPinVec = {10,11,12};
std::vector<int> bPinVec = {13,14,15};
std::vector<int> highEPinVec = {16,17,18};

// MIDI VALUES
const int EStrMidi = 40;
const int AStrMidi = 45;
const int DStrMidi = 50;
const int GStrMidi = 55;
const int BStrMidi = 59;
const int highEStrMidi = 64;


// Active solenoid vectors {pin number : active bool}
std::map<int, bool> activeLowE = {};
std::map<int, bool> activeA = {};
std::map<int, bool> activeD = {};
std::map<int, bool> activeG = {};
std::map<int, bool> activeB = {};
std::map<int, bool> activeHighE = {};

// Pin assignments {midi : pin number}
std::map<int, int> lowEPins = {};
std::map<int, int> aPins = {};
std::map<int, int> dPins = {};
std::map<int, int> gPins = {};
std::map<int, int> bPins = {};
std::map<int, int> highEPins = {};
