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
    void registerMouseCoordinates(int* mouseX, int* mouseY);
    void registerSelectorIconCoordinates(int* x, int* y);

    bool shouldWindowClose = false;
private:
    int* _mouseX;
    int* _mouseY;
    int* _selectIconX;
    int* _selectIconY;
};

#endif  // __EVENT_SYSTEM_H__
