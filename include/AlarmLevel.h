#pragma once
#include <iostream>
#include <unistd.h>
#include <mutex>
#include <thread>
#include <chrono>


enum E_STATE
{
    BEEP = 0,
    WAIT = 1,
    PAUSE = 2,
    NO_ALARM = 3
};

class AlarmLevel
{

    private:

        std::unique_ptr<std::thread> _ringingThread;
        bool _stopAlarm = false;
        std::mutex _stopMutex;

        bool _active;
        std::mutex _activeMutex;

        E_STATE _state = E_STATE::BEEP;

        double _beepTime;
        double _waitTime;
        double _pauseTime;

        int _characterCount = 0;

    public:
    
        AlarmLevel(double beepTime, double waitTime, double pauseTime): _beepTime(beepTime), _waitTime(waitTime), _pauseTime(pauseTime){};

        void ring(); 
        void printCharacter(std::string character);

        void start();
        int stop();
        bool isStop();

        bool isActive();
        void activate();
        void deactivate();

        void setToNoAlarm(){_state = E_STATE::NO_ALARM;};
};