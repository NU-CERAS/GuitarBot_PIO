#pragma once
#include <map>
#include <vector>
using namespace std;
// Number of solenoids per string
extern const int lowESols;
extern const int aSols;
extern const int dSols;
extern const int gSols;
extern const int bSols;
extern const int highESols;

// Pin vectors
extern std::vector<int> lowEPinVec;
extern std::vector<int> aPinVec;
extern std::vector<int> dPinVec;
extern std::vector<int> gPinVec;
extern std::vector<int> bPinVec;
extern std::vector<int> highEPinVec;

/*
MIDI VALUES for each string
*/
extern const int EStrMidi;
extern const int AStrMidi;
extern const int DStrMidi;
extern const int GStrMidi;
extern const int BStrMidi;
extern const int highEStrMidi;

// Active solenoids, key is pin number, value is active state (bool)
extern std::map<int, bool> activeLowE;
extern std::map<int, bool> activeA;
extern std::map<int, bool> activeD;
extern std::map<int, bool> activeG;
extern std::map<int, bool> activeB;
extern std::map<int, bool> activeHighE;

// Key is midi value, value is pin number
extern std::map<int, int> lowEPins;
extern std::map<int, int> aPins;
extern std::map<int, int> dPins;
extern std::map<int, int> gPins;
extern std::map<int, int> bPins;
extern std::map<int, int> highEPins;
