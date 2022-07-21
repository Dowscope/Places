#include "EventSystem.h"

using namespace std;

EventSystem::EventSystem()
{
    std::cout << "EventSystem Starting... ";
    std::cout << "OK!" << std::endl;
}

EventSystem::~EventSystem()
{
    std::cout << "EventSystem Shutting Down... ";
    std::cout << "OK!" << std::endl;
}

void EventSystem::checkEvents()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch (e.type)
        {
        case SDL_QUIT:
            shouldWindowClose = true;
            break;
        default:
            break;
        }
    }
}

