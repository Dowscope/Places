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
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(_mouseX, _mouseY);
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (e.button.button == SDL_BUTTON_LEFT)
            {
                int mouseX = e.button.x;
                int mouseY = e.button.y;
                std::cout << mouseX << "," << mouseY << std::endl;
            }
            break;
        default:
            break;
        }
    }
}

void EventSystem::registerMouseCoordinates(int* mouseX, int* mouseY)
{
    std::cout << "Registering Mouse Coordinates... ";
    _mouseX = mouseX;
    _mouseY = mouseY;
    std::cout << "OK!" << std::endl;
}

void EventSystem::registerSelectorIconCoordinates(int *x, int *y)
{
    std::cout << "Registering Mouse Coordinates... ";
    _selectIconX = x;
    _selectIconY = y;
    std::cout << "OK!" << std::endl;
}
