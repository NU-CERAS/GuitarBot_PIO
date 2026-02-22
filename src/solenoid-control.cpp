#include "solenoid-control.h"
#include "constants.h"
#include <Arduino.h>

// Activates the solenoid on the specified pin for the given string
void solenoidOn(int pin, int stringIndex, Adafruit_MCP23X08 &mcp) {
<<<<<<< HEAD

    if (pin == -1) {
        Serial.println("Open string" + String(stringIndex + 1) + "playing, no solenoid to activate.");
        return;
    }
=======
>>>>>>> ebb925aad10bf6d3932f22d70ebc7d590e155986

    // Check if another solenoid is already active on this string
    bool &activeString = activeStringMaps[stringIndex];
    if(activeString) {
            // Another solenoid is active on this string, ABORT
            Serial.println("Warning: Another solenoid is already active on string " + String(stringIndex + 1));
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
void solenoidOff(int pin, int stringIndex, Adafruit_MCP23X08 &mcp) {
<<<<<<< HEAD
=======
    // Deactivate the solenoid
    mcp.digitalWrite(pin, LOW);
    activeStringMaps[stringIndex] = false;

>>>>>>> ebb925aad10bf6d3932f22d70ebc7d590e155986
    if (pin == -1) {
        Serial.println("Open string" + String(stringIndex + 1) + "done playing, no solenoid to deactivate.");
        return;
    }
    // Deactivate the solenoid
    mcp.digitalWrite(pin, LOW);
    activeStringMaps[stringIndex] = false;


    Serial.print("solenoid off! pin number: ");
    Serial.println(pin);
}