#include "Screen.h"

Screen::Screen(int w, int h, int tileSize):
    _screenHeight(h), _screenWidth(w), _tileSize(tileSize)
{
    std::cout << "Screen is starting... Prepare for initialization" << std::endl;
    _hasInitialized = _initialize();
}

Screen::~Screen()
{
    std::cout << "Screen is shutting down" << std::endl;
    
    std::cout << "Destroying Main Renderer... ";
    SDL_DestroyRenderer(_mainRenderer);
    std::cout << "OK!" << std::endl;

    std::cout << "Destroying Main Window... ";
    SDL_DestroyWindow(_mainWindow);
    std::cout << "OK!" << std::endl;
    
    std::cout << "Shutting Down SDL... ";
    SDL_Quit();
    std::cout << "OK!" << std::endl;

    std::cout << "Screen shut down SUCCESSFUL" << std::endl;
}

bool Screen::_initialize()
{
    std::cout << "Starting Screen Initialization... " << std::endl;

    std::cout << "Initializing SDL... ";
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << std::endl;
        std::cout << "SCREEN.H: SDL Failed = " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "Creating Window... ";
    _mainWindow = SDL_CreateWindow( "Game",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    _screenWidth,
                                    _screenHeight,
                                    0);
    if (!_mainWindow)
    {
        std::cout << std::endl;
        std::cout << "SCREEN.H: Window Creation Failed = " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "Creating Renderer... ";
    _mainRenderer = SDL_CreateRenderer(_mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (!_mainRenderer)
    {
        std::cout << std::endl;
        std::cout << "SCREEN.H: Renderer Creation Failed = " << SDL_GetError() << std::endl;
        return false;
    }
    std::cout << "OK!" << std::endl;

    std::cout << "Initialization Successful" << std::endl;
    return true;
}

void Screen::setTitle(const char* newTitle)
{
    SDL_SetWindowTitle(_mainWindow, newTitle);
}

int Screen::loadSpriteSheet(const char* filePath){
    for (size_t i = 0; i < _spriteSheets.size(); i++){
        if (_spriteSheets[i].first == filePath){
            std::cout << "SpriteSheet - " << filePath << " already loaded" << std::endl;
            return 1;
        }
    }
    SDL_Surface* ss = SDL_LoadBMP(filePath);
    if (!ss) {
        std::cout << "SpriteSheet - " << filePath << " Did not load" << std::endl;
        return 2;
    }
    _spriteSheets.push_back(std::make_pair(filePath, ss));
    return 0;
}

void Screen::clear() {
    SDL_SetRenderDrawColor(_mainRenderer, 0,0,0,255);
}

void Screen::present() {
    SDL_RenderPresent(_mainRenderer);
}

void Screen::drawRect(int x, int y, int r, int g, int b, int a) {
    const SDL_Rect rect = { x * _tileSize, y * _tileSize, _tileSize, _tileSize };
    SDL_SetRenderDrawColor(_mainRenderer, r,g,b,a);
    SDL_RenderFillRect(_mainRenderer, &rect);
}

void Screen::drawTile(int x, int y, int tupe){

}
