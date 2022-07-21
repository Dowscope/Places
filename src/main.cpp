#include <iostream>
#include "Screen.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Declare Functions
void initialize();
void shutdown();

// Declare Global Variables
Screen* screen;

int main(int argc, char const *argv[])
{
    initialize();
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
}

void shutdown()
{
    std::cout << "Game is shutting down" << std::endl;
    delete screen;
    std::cout << "Game Shut Down SUCCESSFUL" << std::endl;
}