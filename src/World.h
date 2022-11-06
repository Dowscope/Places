#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include <cstdlib>
#include <time.h>
#include "Chunk.h"

///////////////////////////////////////////////////////////
/// @brief World
///
class World
{
public:
    static int CHUNKSIZE;

    World(int chunkSize);
    ~World();

    Chunk* getChunkAt(int worldX, int worldY);

    int getCurrentWorldWidth() { return _width; }
    int getCurrentWorldHeight() { return _height; }

private:
    int _width;
    int _height;
    std::vector<Chunk*> _chunks;
};

#endif  // __WORLD_H__
