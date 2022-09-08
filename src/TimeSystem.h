#ifndef __TIME_SYSTEM_H__
#define __TIME_SYSTEM_H__

#include <iostream>
#include <SDL2/SDL.h>

///////////////////////////////////////////////////////////
/// @brief TimeSystem
///
class TimeSystem
{
public:
    TimeSystem();
    TimeSystem(bool debugger);
    ~TimeSystem();
    void gameTimerStart();
    void gameTimerFinish(std::string& currentFPS);
private:
    bool _debug = false;
    uint64_t _gameLoopBegin;
    uint64_t _gameLoopEnd;
    uint32_t _startTicks;
    uint32_t _totalFrames = 0;
    uint32_t _totalFrameTicks = 0;
};

#endif  // __TIME_SYSTEM_H__
