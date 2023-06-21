#include "../include/LevelLow.h"




void LevelLow::ring()
{
    
    unsigned int microseconds = 1000000;
    while(!isStop())
    {
        std::cout << "level low !" << std::endl;
        usleep(microseconds);

    }
    return;
    
}