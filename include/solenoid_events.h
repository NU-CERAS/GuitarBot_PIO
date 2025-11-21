#pragma once

struct SolenoidEvent {
    int pin;
    int stringIndex;
    bool on; 
    // true = activate, false = deactivate
};