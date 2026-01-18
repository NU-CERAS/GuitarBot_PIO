**Dev Log**
</n>
Jan 18 2026:
* Rewrote solenoid control functions for CMOS compatability in cmos branch
* Simplified string pin vector logic in cmos branch
* Plan for next time: Test midi to pin logic with CMOS board

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
