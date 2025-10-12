#include <Arduino.h>
#include "midihandler.h"

void printMIDIMessage() {
    while (usbMIDI.read()) {
        byte type = usbMIDI.getType();
        byte channel = usbMIDI.getChannel();
        byte data1 = usbMIDI.getData1();
        byte data2 = usbMIDI.getData2();

        Serial.print("[MIDI] Type: ");
        Serial.print(type);
        Serial.print(" | Channel: ");
        Serial.print(channel);
        Serial.print(" | Data1 (Note): ");
        Serial.print(data1);
        Serial.print(" | Data2 (Velocity/Value): ");
        Serial.println(data2);
    }
}

void readAndProcessMIDI() {
    while (usbMIDI.read()) { // Process all available incoming MIDI messages
        byte type = usbMIDI.getType();    // Get MIDI message type (Note On, Note Off, etc.)
        byte channel = usbMIDI.getChannel(); // get MIDI channel (1-6 for each string)
        byte note = usbMIDI.getData1();   // Get MIDI note number (which drum or servo to activate)
        byte velocity = usbMIDI.getData2(); // Get MIDI velocity (how hard to hit)
    }
}
