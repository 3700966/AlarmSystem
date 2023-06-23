#include "../include/AlarmLevel.h"



void AlarmLevel::ring()
{
    int beepCount = 0;

    unsigned int microseconds = 250000;
    std::chrono::_V2::system_clock::time_point time = std::chrono::high_resolution_clock::now();
    std::chrono::_V2::system_clock::time_point previousTime = std::chrono::high_resolution_clock::now();

    while(!isStop())
    {

        if(!isActive())
        {
            time = std::chrono::high_resolution_clock::now();
            previousTime = std::chrono::high_resolution_clock::now();
            beepCount = 0;

            if(_state != E_STATE::NO_ALARM)
            { 
                _state = E_STATE::BEEP;
            }
        }
        else
        {

            time = std::chrono::high_resolution_clock::now();
            auto elapsed = time - previousTime;

            double deltaT = std::chrono::duration<double>(elapsed).count();

            if(_state == E_STATE::BEEP) 
            {
                beepCount++;

                std::cout << "X";
                if( deltaT > _beepTime )   
                {
                    previousTime = time;

                    if(beepCount == 5 && _pauseTime > 0)
                    {
                        _state = E_STATE::PAUSE;
                        beepCount = 0;
                    }
                    else
                    {
                        _state = E_STATE::WAIT;
                    }
                }
            }

            else if(_state == E_STATE::WAIT) 
            {
                std::cout << "_";
                if( deltaT > _waitTime - _beepTime )   
                {
                    _state = E_STATE::BEEP;
                    previousTime = time;
                }
            }

            else if(_state == E_STATE::PAUSE) 
            {
                std::cout << "_";
                if( deltaT > _pauseTime )   
                {
                    _state = E_STATE::BEEP;
                    previousTime = time;
                }
            }
            else if(_state == E_STATE::NO_ALARM) 
            {
                std::cout << "_";
            }
        }

        usleep(microseconds);

    }
    return;
    
}


void AlarmLevel::start()
{
    _ringingThread = std::make_unique<std::thread>(ring, this);
}

void AlarmLevel::stop()
{
    _stopMutex.lock();
    _stopAlarm = true;
    _stopMutex.unlock();

    _ringingThread->join();
}

bool AlarmLevel::isStop()
{
    bool stop;
    _stopMutex.lock();
    stop = _stopAlarm;
    _stopMutex.unlock();
    return stop;
}

void AlarmLevel::activate()
{
    _activeMutex.lock();
    _active = true;
    _activeMutex.unlock();
}

void AlarmLevel::deactivate()
{
    _activeMutex.lock();
    _active = false;
    _activeMutex.unlock();
}


bool AlarmLevel::isActive()
{
    bool active;
    _activeMutex.lock();
    active = _active;
    _activeMutex.unlock();
    return active;
}