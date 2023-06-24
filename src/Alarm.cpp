#include "../include/Alarm.h"

Alarm::Alarm()
{
    _alarmLevels.push_back(new AlarmLevel(0.250,    0.5,       2));       // high level first
    _alarmLevels.push_back(new AlarmLevel(0.250,    1,         0));
    _alarmLevels.push_back(new AlarmLevel(1,        30,        0));       // low level last


    _activatedAlarms.push_back(false);
    _activatedAlarms.push_back(false);
    _activatedAlarms.push_back(false);



          // We add a fictionnal lower level to display '_ _ _' when no alarm is active
    _alarmLevels.push_back(new AlarmLevel(0, 0, 0));     
    _alarmLevels[3]->setToNoAlarm();
    _activatedAlarms.push_back(true);


    for(auto level : _alarmLevels)
    {
        level->start();
    }
}


void Alarm::start()
{
    bool alarmOn = true;
    unsigned int microseconds = 1000;

    while(alarmOn)
    {
        
        chooseAlarmToActivate();

        char key = getch(); 

        switch (key)
        {
            case 'q' :
                alarmOn = false;
                break;
            case 3 :
                alarmOn = false;
                break;
            case 'l':
                _activatedAlarms[2] = !_activatedAlarms[2];
                break;
            case 'm':
                _activatedAlarms[1] = !_activatedAlarms[1];
                break;
            case 'h':
                _activatedAlarms[0] = !_activatedAlarms[0];
                break;
            
            default:
                break;
        }
        
        usleep(microseconds); 
    }
    stop();
}

void Alarm::chooseAlarmToActivate()
{
        bool highestLevel = true;
        for(int i = 0; i < 4; i++)
        {
            if( _activatedAlarms[i] == true && highestLevel == true)
            {
                _alarmLevels[i]->activate();
                highestLevel = false;
            }
            else
            {
                _alarmLevels[i]->deactivate();
            }
        }     
}

void Alarm::stop()
{
    int characterCount = 0;
    for(auto level : _alarmLevels)
    {
        characterCount = characterCount + level->stop();
    }

    std::cout << "\nElapsed time : " << characterCount * 250 << " ms ( " << characterCount << " characters printed" << std::endl;
    return;
}