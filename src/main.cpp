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
  for (size_t i = 0; i < (lowEPinVec.size() + 1); i++) {
      if (i == 0) {
        lowEPins[EStrMidi] = -1;
      }
      else {
          lowEPins[EStrMidi + i] = lowEPinVec[i-1];
      }
  }
  for (size_t i = 0; i < (aPinVec.size() + 1); i++) {
      if (i == 0) {
          aPins[AStrMidi] = -1;
      }
      else {
          aPins[AStrMidi + i] = aPinVec[i-1];
      }
  }
  for (size_t i = 0; i < (dPinVec.size() + 1); i++) {
      if (i == 0) {
          dPins[DStrMidi] = -1;
      }
      else {
          dPins[DStrMidi + i] = dPinVec[i-1];
      }
  }
  for (size_t i = 0; i < (gPinVec.size() + 1); i++) {
      if (i == 0) {
          gPins[GStrMidi] = -1;
      }
      else {
          gPins[GStrMidi + i] = gPinVec[i-1];
      }
  }
  for (size_t i = 0; i < (bPinVec.size() + 1); i++) {
      if (i == 0) {
          bPins[BStrMidi] = -1;
      }
      else {
          bPins[BStrMidi + i] = bPinVec[i-1];
      }
  }
  for (size_t i = 0; i < (highEPinVec.size() + 1); i++) {
      if (i == 0) {
          highEPins[highEStrMidi] = -1;
      }
      else {
          highEPins[highEStrMidi + i] = highEPinVec[i-1];
      }
  }
}

void loop() {
  
  //printMIDIMessage();
  Serial.println(lowEPins.size());
  Serial.println(aPins.size());
  Serial.println(dPins.size());
  Serial.println(gPins.size());
  Serial.println(bPins.size());
  Serial.println(highEPins.size());
}

// put function definitions here: