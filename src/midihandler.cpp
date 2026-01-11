#include <Arduino.h>
#include "midihandler.h"
#include "constants.h"
#include "solenoid-control.h"


void readAndProcessMIDI() {
    // Serial.println("midi read");
    // Serial.println("readAndProcessMIDI ran");
    while (usbMIDI.read()) { // Process all available incoming MIDI messages
 
        byte type = usbMIDI.getType();    // Get MIDI message type (Note On, Note Off, etc.)
        byte channel = usbMIDI.getChannel(); // get MIDI channel (1-6 for each string)
        byte note = usbMIDI.getData1();   // Get MIDI note number (which drum or servo to activate)
        byte velocity = usbMIDI.getData2(); // Get MIDI velocity (how hard to hit)

        Serial.print("READ ");

        Serial.print("[MIDI] Type: ");
        Serial.print(type);
        Serial.print(" | Channel: ");
        Serial.print(channel);
        Serial.print(" | Data1 (Note): ");
        Serial.print(note);
        Serial.print(" | Data2 (Velocity/Value): ");
        Serial.println(velocity);

        // handles midi by channel, channel 1: E (lower) -> channel 6: E (higher) 
        //TODO: use the array and index the array
        if (channel == 0) processMIDIByChannel(type, channel, note, velocity, string1MidiToPin);
        else if (channel == 1) processMIDIByChannel(type, channel, note, velocity, string2MidiToPin);
        else if (channel == 2) processMIDIByChannel(type, channel, note, velocity, string3MidiToPin);
        else if (channel == 3) processMIDIByChannel(type, channel, note, velocity, string4MidiToPin);
        else if (channel == 4) processMIDIByChannel(type, channel, note, velocity, string5MidiToPin);
        else if (channel == 5) processMIDIByChannel(type, channel, note, velocity, string6MidiToPin);
    }

}

// function that handles a midi signal by channel, channel 1: E (lower) -> channel 6: E (higher) 
void processMIDIByChannel(byte type, byte channel, byte note, byte velocity, std::map<int, int>midiToPinDict) {
    // maps the midi to solenoid
    int solenoidPin = midiToPinDict[note]; 

    Serial.println("type:");
    Serial.println(type);
    // turns solenoid on
    if (type == usbMIDI.NoteOn && velocity > 0) {
        Serial.println("noteon!"); 
        solenoidOn(solenoidPin, channel - 1, stringMCPs[channel - 1]); // channel - 1 to match string index
    }

    // treats NoteOn with velocity 0 as NoteOff
    else if (type == usbMIDI.NoteOn && velocity == 0) {
        solenoidOff(solenoidPin, channel - 1, stringMCPs[channel - 1]);
    }

    // turns solenoid off
    else if (type == usbMIDI.NoteOff) {
        solenoidOff(solenoidPin, channel - 1, stringMCPs[channel - 1]); // channel - 1 to match string index
    }


    

}