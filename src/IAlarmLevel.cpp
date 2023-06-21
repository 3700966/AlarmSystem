#include "../include/IAlarmLevel.h"





void IAlarmLevel::start()
{
    _ringingThread = std::make_unique<std::thread>(ring, this);
}




void IAlarmLevel::stop()
{
    _stopMutex.lock();
    _stopAlarm = true;
    _stopMutex.unlock();

    _ringingThread->join();
    std::cout << "bye" << std::endl;
}

bool IAlarmLevel::isStop()
{
    bool stop;
    _activeMutex.lock();
    stop = _stopAlarm;
    _activeMutex.unlock();
    return stop;
}

void IAlarmLevel::activate()
{
    _activeMutex.lock();
    _active = true;
    _activeMutex.unlock();
}

void IAlarmLevel::deactivate()
{
    _activeMutex.lock();
    _active = false;
    _activeMutex.unlock();
}


bool IAlarmLevel::isActive()
{
    bool active;
    _activeMutex.lock();
    active = _active;
    _activeMutex.unlock();
    return active;
}