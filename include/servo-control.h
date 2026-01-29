#pragma once
#include <Arduino.h>
#include <Adafruit_MCP23X17.h>
#include <Servo.h>

void initializeServos();

void updateServoHits();

int adjustedVelocityControlByte(int velocityControlByte);

int velocityControl(int changedVelocityControlByte, int servoIndex);
