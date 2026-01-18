#include "solenoid-control.h"
#include "constants.h"
#include <Arduino.h>

// need to write to 2 pins?
// PMOS active low
// NMOS active high
// base 4 counting system
// 4 digit is PMOS
// 1 digit is NMOS
// to write to solenoid n, set PMOS to (n // 4) and NMOS to (n % 4)

// Activates the solenoid on the specified pin for the given string
void solenoidOn(int pin, int stringIndex, Adafruit_MCP23X17 &mcp) {

    // Check if another solenoid is already active on this string
    bool &activeString = activeStringMaps[stringIndex];
    if(activeString) {
            // Another solenoid is active on this string, ABORT
            Serial.println("Warning: Another solenoid is already active on string " + String(stringIndex + 1));
            return;
        
    }

    // check if solenoid actuation needed
    if (pin == -1) {
        activeString = true;
        return;
    }

    // Activate the solenoid
    // Calculate PMOS and NMOS values
    int pmosValue = (int) std::floor(pin / 4);
    int nmosValue = pin % 4;

    turnOff(pmosValue, mcp); // Activate PMOS
    turnOn(nmosValue, mcp); // Activate NMOS
    Serial.println("solenoid on! pin number:");
    Serial.println(pin);

    // Mark this solenoid as active
    activeString = true;
    }

// Deactivates the solenoid on the specified pin for the given string
void solenoidOff(int pin, int stringIndex, Adafruit_MCP23X17 &mcp) {

    // no solenoid to turn off
    if (pin == -1) {
        activeStringMaps[stringIndex] = false;
        return;
    }

    // Deactivate the solenoid
    // Calculate PMOS and NMOS values
    int pmosValue = (int) std::floor(pin / 4);
    int nmosValue = pin % 4;

    turnOn(pmosValue, mcp); // Deactivate PMOS
    turnOff(nmosValue, mcp); // Deactivate NMOS
    activeStringMaps[stringIndex] = false;


}

void turnOn(int pin, Adafruit_MCP23X17 &mcp) {
    mcp.digitalWrite(pin, HIGH);
}
void turnOff(int pin, Adafruit_MCP23X17 &mcp) {
    mcp.digitalWrite(pin, LOW);
}