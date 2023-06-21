#include "../include/Alarm.h"
#include "../include/LevelLow.h"
#include "../include/LevelMedium.h"
#include "../include/LevelHigh.h"

Alarm::Alarm()
{
    _alarmLevels.push_back(new LevelHigh());
    _alarmLevels.push_back(new LevelMedium());
    _alarmLevels.push_back(new LevelLow());

    for(IAlarmLevel* level : _alarmLevels)
    {
        level->start();
    }

    start();
}


void Alarm::start()
{
    bool alarmOn = true;
    while(alarmOn)
    {
        char key = getch(); 
        if( key == 'q' ) // & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            alarmOn = false;
        }
        
    }
}


void Alarm::stop()
{
    for(IAlarmLevel* level : _alarmLevels)
    {
        level->stop();
    }
    return;
}