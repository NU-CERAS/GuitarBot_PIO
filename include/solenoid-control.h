#pragma once

#include <Arduino.h>
#include <Adafruit_MCP23X08.h>

void initializeSolenoids();

void solenoidOn(int pin, int stringIndex, Adafruit_MCP23X08 &mcp);
void solenoidOff(int pin, int stringIndex, Adafruit_MCP23X08 &mcp);