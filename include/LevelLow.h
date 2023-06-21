#pragma once
#include "IAlarmLevel.h"



class LevelLow : public IAlarmLevel
{

    private:

    public:
        LevelLow();
        void ring(); 
};