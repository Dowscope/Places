#include "TimeSystem.h"

using namespace std;

TimeSystem::TimeSystem()
{
    std::cout << "TimeSystem Starting... ";
    std::cout << "OK!" << std::endl;
}

TimeSystem::TimeSystem(bool debugger)
{
    if (debugger){
        std::cout << "TimeSystem Starting in DEBUG mode... ";
    }
    else {
        std::cout << "TimeSystem Starting... ";
    }
    _debug = debugger;
    std::cout << "OK!" << std::endl;
}

TimeSystem::~TimeSystem()
{
    if (_debug){
        std::cout << "TimeSystem Shutting Down (DEBUG MODE)... ";
    }
    else 
    {
        std::cout << "TimeSystem Shutting Down... ";
    }
    std::cout << "OK!" << std::endl;
}

void TimeSystem::gameTimerStart()
{
    _gameLoopBegin =  SDL_GetPerformanceCounter();
    _startTicks = SDL_GetTicks();
    _totalFrames++;
}

void TimeSystem::gameTimerFinish(std::string& currentFPS)
{
    _gameLoopEnd = SDL_GetPerformanceCounter();
    uint32_t endTicks = SDL_GetTicks();
    uint64_t framePerf = _gameLoopEnd - _gameLoopBegin;
    float frameTime = (endTicks - _startTicks) / 1000.0f;
    _totalFrameTicks += endTicks - _startTicks;

    const float elapsed = (_gameLoopEnd - _gameLoopBegin) / (float)SDL_GetPerformanceFrequency();
    const float elapsedMS = (_gameLoopEnd - _gameLoopBegin) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
    SDL_Delay(abs(16.666f - elapsedMS));

    
    currentFPS = to_string(1.0f / frameTime);

    if (_debug){
        std::cout << "FrameTime: " << to_string(frameTime) << std::endl;
        std::cout << "Current FPS: " << currentFPS << std::endl;
        std::cout << "Average FPS: " << to_string(1000.0f / ((float)_totalFrameTicks / _totalFrames)) << std::endl;
        std::cout << "Current PREF: " << to_string(framePerf) << std::endl;
    }
}
