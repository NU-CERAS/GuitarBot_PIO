#pragma once
#include <Arduino.h>
#include <Adafruit_MCP23X08.h>
#include <map>
#include <iostream>

extern Adafruit_MCP23X08 stringMCPs[];

void printMIDIMessage();
void readAndProcessMIDI();
void processMIDIByChannel(byte type, byte channel, byte note, byte velocity, std::map<int, int>midiToPinDict);