#include <iostream>
#include "Screen.h"
#include "EventSystem.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Declare Functions
void initialize();
void shutdown();
void update();
void render();

// Declare Global Variables
Screen* screen;
EventSystem* eventSystem;

int main(int argc, char const *argv[])
{
    initialize();

    std::cout << "Game Started... " << std::endl;
    while(!eventSystem->shouldWindowClose)
    {
        eventSystem->checkEvents();
    }

    shutdown();
    return 0;
}

void initialize()
{
    std::cout << "\x1B[2J\x1B[H"; // Clears Console
    std::cout << std::endl;
    std::cout << " ///////////          /////////  " << std::endl;
    std::cout << " /////////////      //////////// " << std::endl;
    std::cout << " ///        ///    ///        ///" << std::endl;
    std::cout << " ///         ///    ///       ///" << std::endl;
    std::cout << " ///         ///     /////" << std::endl;
    std::cout << " ///         ///       //////" << std::endl;
    std::cout << " ///         ///          /////" << std::endl;
    std::cout << " ///         ///              ///" << std::endl;
    std::cout << " ///        ///    ///       ///" << std::endl;
    std::cout << " /////////////      //////////" << std::endl;
    std::cout << " ///////////         ///////" << std::endl;
    std::cout << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "The game is now initializing" << std::endl;
    screen = new Screen(SCREEN_WIDTH, SCREEN_HEIGHT);
    eventSystem = new EventSystem();
}

void shutdown()
{
    std::cout << "Game is shutting down" << std::endl;
    delete screen;
    delete eventSystem;
    std::cout << "Game Shut Down SUCCESSFUL" << std::endl;
}

// This function is called every loop and does the updates to the game
void update()
{

}

// this function is called every frame and renders the graphics to the window
void render()
{

}
