#pragma once
#include <map>
#include <vector>
// using namespace std;
// Number of solenoids per string
const int lowESols;
const int aSols;
const int dSols;
const int gSols;
const int bSols;
const int highESols;

// Pin vectors
vector<int> lowEPinVec;
vector<int> aPinVec;
vector<int> dPinVec;
vector<int> gPinVec;
vector<int> bPinVec;
vector<int> highEPinVec;

/*
MIDI VALUES for each string
*/
const int E2;
const int A2;
const int D3;
const int G3;
const int B3;
const int E4;

// Active solenoids, key is pin number, value is active state (bool)
map<int, bool> activeLowE;
map<int, bool> activeA;
map<int, bool> activeD;
map<int, bool> activeG;
map<int, bool> activeB;
map<int, bool> activeHighE;

// Key is midi value, value is pin number
map<int, int> lowEPins;
map<int, int> aPins;
map<int, int> dPins;
map<int, int> gPins;
map<int, int> bPins;
map<int, int> highEPins;
