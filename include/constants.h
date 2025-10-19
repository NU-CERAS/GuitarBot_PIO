#pragma once
#include <map>
#include <vector>
using namespace std;
// MIDI Constants
const int lowESols;
const int aSols;
const int dSols;
const int gSols;
const int bSols;
const int highESols;

// Active solenoid vectors
map<int, bool> activeE;
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
