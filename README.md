# backpack
technical test for iFollow _ Q1

This repository contains an implementation for an alarm system.

------------------------------------
    IMPORTANT :
This code has been written for windows, 
the conio library will probably not be available on different OS, such as Linux ones.
------------------------------------

How to build :

This project has been built on windows, using minGW.
If minGW and make are installed, just run "make" at the root of this folder

How to run :

Once built, the executable will be in the bin folder. Just run it from the root "./bin/alarmSystem.exe"

How to use :

When running, the alarm will be continuously displaying "_" characters.
Press the 'l', 'm' and 'h' keys to request the low, medium and high levels respectively, or 'unrequest' them if they were already requested.
At all times, the alarm will ring to the highest requested level.
Press 'q' or 'CTRL+C' to exit the program.
 
How it works :

Most of the job is done by Alarm.cpp.
It does 3 things :
- it creates 3 AlarmLevels, initializes them, starts them and stops them when asked to
- it runs in a loop to read keyboard inputs
- it stores a vector of alarm levels that were requested by the user, and upon any keyboard input, it reads it to activate the highest priority alarm requested, and desactivates every other.

The AlarmLevels are more simple, they share the same state machine, which is represented by the ring() function.
The difference between them are the duration of beeps and silences, aswell as the fact that the highest level has a bit of a twist because it also has a pause every 5 rings. 
This is managed by the 3 attributes beep, wait and pause time of the class (we don't use the pause state when the pause time is set to 0).
There is also a 4rth alarmLevel, which is not requestable by the user, so it's always requested. It is used to print silences when no alarm level is active, so the state machine has a state "no alarm" that is permanent, just for this case. 


