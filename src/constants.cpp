#include "constants.h"
using namespace std;

// 5 is arbitrary
const int lowESols = 5;
const int aSols = 5;   
const int dSols = 5;
const int gSols = 5;
const int bSols = 5;
const int highESols = 5;

// Active solenoid vectors
vector<int> activeE = {};
vector<int> activeA = {};   
vector<int> activeD = {};
vector<int> activeG = {};
vector<int> activeB = {};
vector<int> activeHighE = {};

// Pin assignments
unordered_map<int, int> lowEPins = {};
unordered_map<int, int> aPins = {};
unordered_map<int, int> dPins = {};
unordered_map<int, int> gPins = {};
unordered_map<int, int> bPins = {};
unordered_map<int, int> highEPins = {};
