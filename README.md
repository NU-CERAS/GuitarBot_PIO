**Dev Log**
</n>

Jan 25 2026:
* Tested solenoid control with multi-channel midi inputs
* Updated initialization for test board
* Next time: Confirm board design with electrical, move on to servo actuation?

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
