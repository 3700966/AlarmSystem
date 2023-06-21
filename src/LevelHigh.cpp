#include "../include/LevelHigh.h"


void LevelHigh::ring()
{
    
    unsigned int microseconds = 1000000;
    while(!isStop())
    {
        std::cout << "level high !" << std::endl;
        usleep(microseconds);

    }
    return;
    
}