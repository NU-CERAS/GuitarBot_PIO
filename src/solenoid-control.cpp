#include "solenoid-control.h"
#include "constants.h"
#include <Arduino.h>

// Activates the solenoid on the specified pin for the given string
void solenoidOn(int pin, int stringIndex, Adafruit_MCP23X17 &mcp) {

    // Check if another solenoid is already active on this string
    bool &activeString = activeStringMaps[stringIndex];
    if(activeString) {
            // Another solenoid is active on this string, ABORT
            Serial.println("Warning: Another solenoid is already active on string " + String(stringIndex + 1));
            return;
        
    }

    if (pin == -1) {
        Serial.println("Open string" + String(stringIndex + 1) + "playing, no solenoid to activate.");
        return;
    }

    // Activate the solenoid
    mcp.digitalWrite(pin, HIGH);
    Serial.print("solenoid on! pin number: ");
    Serial.println(pin);

    // Mark this solenoid as active
    activeString = true;
    }

// Deactivates the solenoid on the specified pin for the given string
void solenoidOff(int pin, int stringIndex, Adafruit_MCP23X17 &mcp) {
    // Deactivate the solenoid
    mcp.digitalWrite(pin, LOW);
    activeStringMaps[stringIndex] = false;

    if (pin == -1) {
        Serial.println("Open string" + String(stringIndex + 1) + "done playing, no solenoid to deactivate.");
        return;
    }

    Serial.print("solenoid off! pin number: ");
    Serial.println(pin);
}