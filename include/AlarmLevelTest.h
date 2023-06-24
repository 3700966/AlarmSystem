#pragma once
#include "AlarmLevel.h"



class AlarmLevelTest : public AlarmLevel
{

    private:
        std::string _printed = "";

    public:
    
        AlarmLevelTest(double beepTime, double waitTime, double pauseTime): AlarmLevel {beepTime, waitTime, pauseTime}{};

        void printCharacter(std::string character) override;
        const std::string getPrinted() const {return _printed;};
};