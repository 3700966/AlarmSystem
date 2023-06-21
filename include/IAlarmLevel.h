#pragma once
#include <iostream>
#include <unistd.h>
#include <conio.h>
#include <mutex>
#include <thread>

class IAlarmLevel
{

    private:

        
        std::unique_ptr<std::thread> _ringingThread;
        bool _stopAlarm = false;
        std::mutex _stopMutex;

        bool _active;
        std::mutex _activeMutex;

    public:
        virtual void ring() = 0; 

        void start();
        void stop();
        bool isStop();

        bool isActive();
        void activate();
        void deactivate();
};