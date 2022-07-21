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
    // TODO: Needs implementation
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
    std::cout << "OK" << std::endl;


    std::cout << "Initialization Successful" << std::endl;
    return true;
}