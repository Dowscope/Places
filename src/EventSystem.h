#ifndef __EVENT_SYSTEM_H__
#define __EVENT_SYSTEM_H__

#include <SDL2/SDL.h>
#include <iostream>

///////////////////////////////////////////////////////////
/// @brief EventSystem
///
class EventSystem
{
public:
    EventSystem();
    ~EventSystem();
    void checkEvents();

    bool shouldWindowClose = false;
private:
    // Members
};

#endif  // __EVENT_SYSTEM_H__
