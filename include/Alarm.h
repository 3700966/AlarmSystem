#pragma once
#include "AlarmLevel.h"

#include <conio.h>
#include <map>
#include <vector>

class Alarm
{
    private:

        std::vector<AlarmLevel*> _alarmLevels;
        std::vector<bool> _activatedAlarms;         // ordered by priority, contains whether the user wants the alarm to be activated. This doesn't say if it is actually ringing !

    public:

        Alarm();

        void chooseAlarmToActivate();
        
        void start();
        void stop();


};