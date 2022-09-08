#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include <cstdlib>
#include <time.h>
#include "Tile.h"

///////////////////////////////////////////////////////////
/// @brief World
///
class World
{
public:
    World(int w, int h);
    ~World();

    int getCurrentWorldWidth() { return _width; }
    int getCurrentWorldHeight() { return _height; }
    std::vector<Tile*>* getTiles() { return &_tiles; }

private:
    int _width;
    int _height;
    std::vector<Tile*> _tiles;
};

#endif  // __WORLD_H__
