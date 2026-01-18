#pragma once

#include <Arduino.h>
#include <Adafruit_MCP23X17.h>
#include <cmath>

void solenoidOn(int pin, int stringIndex, Adafruit_MCP23X17 &mcp);
void solenoidOff(int pin, int stringIndex, Adafruit_MCP23X17 &mcp);

void turnOn(int pin, Adafruit_MCP23X17 &mcp);
void turnOff(int pin, Adafruit_MCP23X17 &mcp);