#include "../include/LevelMedium.h"



void LevelMedium::ring()
{
    
    unsigned int microseconds = 1000000;
    while(!isStop())
    {
        std::cout << "level medium !" << std::endl;
        usleep(microseconds);

    }
    return;
    
}