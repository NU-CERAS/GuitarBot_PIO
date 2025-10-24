#include <Arduino.h>
#include "midihandler.h"
#include "constants.h"

// void printMIDIMessage() {
//     while (usbMIDI.read()) {
//         byte type = usbMIDI.getType();
//         byte channel = usbMIDI.getChannel();
//         byte data1 = usbMIDI.getData1();
//         byte data2 = usbMIDI.getData2();

//         Serial.print("[MIDI] Type: ");
//         Serial.print(type);
//         Serial.print(" | Channel: ");
//         Serial.print(channel);
//         Serial.print(" | Data1 (Note): ");
//         Serial.print(data1);
//         Serial.print(" | Data2 (Velocity/Value): ");
//         Serial.println(data2);
//     }
// }

void readAndProcessMIDI() {
    while (usbMIDI.read()) { // Process all available incoming MIDI messages
        byte type = usbMIDI.getType();    // Get MIDI message type (Note On, Note Off, etc.)
        byte channel = usbMIDI.getChannel(); // get MIDI channel (1-6 for each string)
        byte note = usbMIDI.getData1();   // Get MIDI note number (which drum or servo to activate)
        byte velocity = usbMIDI.getData2(); // Get MIDI velocity (how hard to hit)

        // handles midi by channel, channel 1: E (lower) -> channel 6: E (higher) 
        if (note == 1) processMIDIByChannel(type, channel, note, velocity, lowEPins);
        else if (note == 2) processMIDIByChannel(type, channel, note, velocity, aPins);
        else if (note == 3) processMIDIByChannel(type, channel, note, velocity, dPins);
        else if (note == 4) processMIDIByChannel(type, channel, note, velocity, gPins);
        else if (note == 5) processMIDIByChannel(type, channel, note, velocity, bPins);
        else if (note == 6) processMIDIByChannel(type, channel, note, velocity, highEPins);
    }

}

// function that handles a midi signal by channel, channel 1: E (lower) -> channel 6: E (higher) 
void processMIDIByChannel(byte type, byte channel, byte note, byte velocity, std::map<int, int>midiToPinDict) {
    // maps the midi to solenoid
    int solenoidPin = midiToPinDict[note];

    // turns solenoid on
    if (type == usbMIDI.NoteOn) {
        
    }

    // turns solenoid off
    else if (type == usbMIDI.NoteOff) {

    }

}