#include "constants.h"
using namespace std;

// Number of solenoids per string
// 5 is arbitrary
const int lowESols = 5;
const int aSols = 5;   
const int dSols = 5;
const int gSols = 5;
const int bSols = 5;
const int highESols = 5;

// Pin vectors, MUST be in consecutive order from lowest to highest solenoid
vector<int> lowEPinVec = {};
vector<int> aPinVec = {};
vector<int> dPinVec = {};
vector<int> gPinVec = {};
vector<int> bPinVec = {};
vector<int> highEPinVec = {};

// MIDI VALUES
const int E2 = 40;
const int A2 = 45;
const int D3 = 50;
const int G3 = 55;
const int B3 = 59;
const int E4 = 64;


// Active solenoid vectors {pin number : active bool}
map<int, bool> activeLowE = {};
map<int, bool> activeA = {};
map<int, bool> activeD = {};
map<int, bool> activeG = {};
map<int, bool> activeB = {};
map<int, bool> activeHighE = {};

// Pin assignments {midi : pin number}
map<int, int> lowEPins = {};
map<int, int> aPins = {};
map<int, int> dPins = {};
map<int, int> gPins = {};
map<int, int> bPins = {};
map<int, int> highEPins = {};
