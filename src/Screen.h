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
    Screen(int w, int h, int tileSize);
    ~Screen();
    bool didInitialize(){return _hasInitialized;}
    void setTitle(const char* newTitle);
    void clear();
    void present();
    void drawRect(int x, int y, int r, int g, int b, int a);
private:
    int _screenWidth, _screenHeight, _tileSize;
    bool _hasInitialized = false;
    SDL_Window* _mainWindow;
    SDL_Renderer* _mainRenderer;

    bool _initialize();
};

#endif  // __SCREEN_H__
