**Dev Log**
</n>

March 1 2026:
* Tested and made sure a singular solenoid works on the updated two-multiplexer code
* Copied and pasted servo code to both LED Testing (two multiplexer code) and 08-LED Testing branches
* Instructions for testing solenoids and servos simultaneously, for next time:
    * plug laptop to other teensy (servo)
    * anything coming from the original teensy is now coming from the new teensy
    * green and yellow wires: new teensy -> 2nd board
    * (move g and y to new teensy from old, but they are switched)
    * connect ground to ground and power to power
    * careful about which power! teensy power has to go where teensy power was (3V, red wire from screw terminatl to old teensy -> 3V)
    * power to power (big power from new teensy can go inside DC power supply along with the regular thin wires)


February 25 2026:
* Small structural fixes to reduce errors during testing
* Next time: Test solenoid and servo actuation with midi notes at same time

Jan 28 2026:
* Refactored drummer bot servo code for guitar servo actuation, including constants and control
* Updated midihandler to include servo state updates
* UPDATED PARTH'S VS CODE
* Next time: Test solenoid code with real solenoids and/or test servo code on makeshift setup

Jan 18 2026:
* Cleaned up constants files and replaced MCP23008 with MCP23017
* Updated solenoid control to handle open strings
* Next time: Test midi handling with LED array, consult with electrical on future of chip design

Jan 11 2026:
* MIDI pipeline working for midihandler.cpp - no note conflicts or odd inputs
* No need for RTOS
* Plan for next time: make sure everything is logically sound (solenoid control code)
* Figure out the 16 LED lights board & how to work with it (or wait for testboard)

Nov 13 2025:
* Look into RTOS to guarantee each note on and note off is read one time, sequentially
* RTOS - modify old code to integrate (potentially start from scratch?)

Nov 9 2025:
* Note 67 causes a solenoid conflict
* Notes are all coming from channel 1 for some reason
* Note type 176 with random channels - Cakewalk deprecation?
