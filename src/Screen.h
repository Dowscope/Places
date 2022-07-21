#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>
#include <SDL2/SDL.h>

///////////////////////////////////////////////////////////
/// @brief Screen
///
class Screen
{
public:
    Screen(int w, int h);
    ~Screen();
    bool didInitialize(){return _hasInitialized;}
private:
    int _screenWidth, _screenHeight;
    bool _hasInitialized = false;

    bool _initialize();
};

#endif  // __SCREEN_H__
