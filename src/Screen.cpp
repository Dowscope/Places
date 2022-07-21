#include "Screen.h"

using namespace std;

Screen::Screen(int w, int h):
    _screenHeight(h), _screenWidth(w)
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
    _mainWindow = SDL_CreateWindow( "Places",
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