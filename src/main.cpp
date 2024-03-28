#include <iostream>
#include <string>
#include "Screen.h"
#include "EventSystem.h"
#include "TimeSystem.h"
#include "World.h"
#include "Chunk.h"
#include "Tile.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 64
#define CHUNK_SIZE 8

#define DEBUGGER_SW false

// Declare Functions
void initialize();
void shutdown();
void update();
void render();

// Declare Global Variables
Screen* screen;
EventSystem* eventSystem;
TimeSystem* timeSystem;

World* world;

int mouseX, mouseY, selectIconX, selectIconY;

int main(int argc, char const *argv[])
{
    initialize();

    std::cout << "Game Started... " << std::endl;
    while(!eventSystem->shouldWindowClose)
    {
        timeSystem->gameTimerStart();
        eventSystem->checkEvents();
        update();

        screen->clear();
        render();
        screen->present();

        std::string fps = "";
        timeSystem->gameTimerFinish(fps);
        screen->setTitle(fps.c_str());
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
    screen = new Screen(SCREEN_WIDTH, SCREEN_HEIGHT, TILE_SIZE);
    screen->setTitle("Places");

    eventSystem = new EventSystem();
    eventSystem->registerMouseCoordinates(&mouseX, &mouseY);
    eventSystem->registerSelectorIconCoordinates(&selectIconX, &selectIconY);

    timeSystem = new TimeSystem(DEBUGGER_SW);
    world = new World(CHUNK_SIZE);
}

void shutdown()
{
    std::cout << "Game is shutting down" << std::endl;
    delete timeSystem;
    delete eventSystem;
    delete screen;
    std::cout << "Game Shut Down SUCCESSFUL" << std::endl;
}

// This function is called every loop and does the updates to the game
void update()
{
    
}

// this function is called every frame and renders the graphics to the window
void render()
{
    auto c = world->GetChunkAt(0,0);
    
    for (size_t y = 0; y < CHUNK_SIZE; y++)
    {
        for (size_t x = 0; x < CHUNK_SIZE; x++)
        {
            auto t = ((c.value()).GetChunkTileAt(x,y).value());
            screen->drawRect(t.getX(),t.getY(), 0, 255, 25, 255, CHUNK_SIZE);
        }
        
    }
}
