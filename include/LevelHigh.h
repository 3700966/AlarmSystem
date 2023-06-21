#pragma once
#include "IAlarmLevel.h"



class LevelHigh : public IAlarmLevel
{

    private:

    public:
        LevelHigh();
        void ring(); 
};