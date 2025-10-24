#include <Arduino.h>
#include "midihandler.h"
#include "constants.h"
#include <iostream>
// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Initialize active solenoid maps
  for (int pin : lowEPinVec) {
      activeLowE[pin] = false;
  }
  for (int pin : aPinVec) {
      activeA[pin] = false;
  }
  for (int pin : dPinVec) {
      activeD[pin] = false;
  }
  for (int pin : gPinVec) {
      activeG[pin] = false;
  }
  for (int pin : bPinVec) {
      activeB[pin] = false;
  }
  for (int pin : highEPinVec) {
      activeHighE[pin] = false;
  }

  // Initialize midi to pin assignment maps
  for (int i = 0; i < (lowEPinVec.size() + 1); i++) {
      if (i == 0) {
        lowEPins[E2] = -1;
      }
      else {
          lowEPins[E2 + i] = lowEPinVec[i-1];
      }
  }
  for (int i = 0; i < (aPinVec.size() + 1); i++) {
      if (i == 0) {
          aPins[A2] = -1;
      }
      else {
          aPins[A2 + i] = aPinVec[i-1];
      }
  }
  for (int i = 0; i < (dPinVec.size() + 1); i++) {
      if (i == 0) {
          dPins[D3] = -1;
      }
      else {
          dPins[D3 + i] = dPinVec[i-1];
      }
  }
  for (int i = 0; i < (gPinVec.size() + 1); i++) {
      if (i == 0) {
          gPins[G3] = -1;
      }
      else {
          gPins[G3 + i] = gPinVec[i-1];
      }
  }
  for (int i = 0; i < (bPinVec.size() + 1); i++) {
      if (i == 0) {
          bPins[B3] = -1;
      }
      else {
          bPins[B3 + i] = bPinVec[i-1];
      }
  }
  for (int i = 0; i < (highEPinVec.size() + 1); i++) {
      if (i == 0) {
          highEPins[E4] = -1;
      }
      else {
          highEPins[E4 + i] = highEPinVec[i-1];
      }
  }
  std::cout << lowEPins.size() << std::endl;
  std::cout << aPins.size() << std::endl;
  std::cout << dPins.size() << std::endl;
  std::cout << gPins.size() << std::endl;
  std::cout << bPins.size() << std::endl;
  std::cout << highEPins.size() << std::endl;
}

void loop() {
  
  printMIDIMessage();
}

// put function definitions here: