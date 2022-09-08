#include "World.h"

World::World(int w, int h):
    _width(w), _height(h)
{
    // Intialize Rand
    srand (time(NULL));
    
    for (int y = 0; y < _height; y++){
        for (int x = 0; x < _width; x++) {
            _tiles.push_back(new Tile(x, y, rand() % 2));
        }
    }
}

World::~World()
{
    // TODO: Needs implementation
}
