#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <iostream>
#include <vector>
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
    int loadSpriteSheet(const char* filePath);
    void clear();
    void present();
    void drawSelectIcon(int x, int y);
    void drawRect(int x, int y, int r, int g, int b, int a, int chunksize);
    void drawTile(int x, int y, int type);
private:
    int _screenWidth, _screenHeight, _tileSize;
    bool _hasInitialized = false;
    SDL_Window* _mainWindow;
    SDL_Renderer* _mainRenderer;
    std::vector<std::pair<const char*, SDL_Surface*>> _spriteSheets;

    bool _initialize();
};

#endif  // __SCREEN_H__
