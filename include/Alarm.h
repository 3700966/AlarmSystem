#pragma once
#include "IAlarmLevel.h"
#include <vector>

class Alarm
{
    private:

        std::vector<IAlarmLevel*> _alarmLevels;

    public:

        Alarm();

        void start();
        void stop();


};