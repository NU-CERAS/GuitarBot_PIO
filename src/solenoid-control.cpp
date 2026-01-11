#include "solenoid-control.h"
#include "constants.h"
#include <Arduino.h>

void initializeSolenoids() {
/*
  for (int n = 0; n < 6; n++) {
    for (int i = 0; i < NUM_SERVOS; i++) {
        servos[i].attach(servoPins[i]);    // Attach the servo to its PWM pin
        servos[i].write(neutPos[i]);        // Move the servo to its neutral position

        hatPedServo.attach(HATP_SERVO_PIN);
        hatPedServo.write(hatPedRestAngle); // Start in resting position  
    }
  }
*/
}

// Activates the solenoid on the specified pin for the given string
void solenoidOn(int pin, int stringIndex, Adafruit_MCP23X08 &mcp) {

    // Check if another solenoid is already active on this string
    std::map<int, bool> &activeMap = activeStringMaps[stringIndex];
    for (std::pair<const int, bool> &solenoid : activeMap) {
        if (solenoid.second) {
            // Another solenoid is active on this string, ABORT
            Serial.println("Warning: Another solenoid is already active on string " + String(stringIndex + 1));
            return;
        }
    }

    // Activate the solenoid
    // mcp.digitalWrite(pin, HIGH);
    Serial.println("solenoid on! pin number:");
    Serial.println(pin);

    // Mark this solenoid as active
    activeMap[pin] = true;
}

// Deactivates the solenoid on the specified pin for the given string
void solenoidOff(int pin, int stringIndex, Adafruit_MCP23X08 &mcp) {
    // mcp.digitalWrite(pin, LOW);
    activeStringMaps[stringIndex][pin] = false;
}