#pragma once
#include <Arduino.h>
#include <Adafruit_MCP23X08.h>

extern Adafruit_MCP23X08 stringMCPs[];

void printMIDIMessage();
void readAndProcessMIDI();
void processMIDIByChannel();