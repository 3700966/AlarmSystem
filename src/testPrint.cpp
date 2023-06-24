#include "../include/AlarmLevelTest.h"

#define EXECTIME 10000000

bool printLowAlarm()
{
    AlarmLevelTest low(1,        30,        0);
    
    low.start();
    usleep(250);
    low.activate();
    
    usleep(EXECTIME);
    
    low.deactivate();
    int nbCharacters = low.stop();
    std::string printed = low.getPrinted();

    if(nbCharacters != EXECTIME / 250000) return false;
    std::cout << "printed : " << printed << std::endl;
    return true;
}

bool printMediumAlarm()
{
    AlarmLevelTest medium(0.250,    1,         0);

    medium.start();
    usleep(250);
    medium.activate();
    
    usleep(EXECTIME);
    
    medium.deactivate();
    int nbCharacters = medium.stop();
    std::string printed = medium.getPrinted();

    if(nbCharacters != EXECTIME / 250000) return false;
    std::cout << "printed : " << printed << std::endl;
    return true;
}

bool printHighAlarm()
{
    AlarmLevelTest high(0.250,    0.5,       2);
    
    high.start();
    usleep(250);
    high.activate();
    
    usleep(EXECTIME);
    
    high.deactivate();
    int nbCharacters = high.stop();
    std::string printed = high.getPrinted();

    if(nbCharacters != EXECTIME / 250000) return false;
    std::cout << "printed : " << printed << std::endl;
    return true;
}
