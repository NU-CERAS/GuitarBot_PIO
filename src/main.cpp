#include <Arduino.h>
#include "midihandler.h"

// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  
  printMIDIMessage();
}

// put function definitions here: