#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include <cstdlib>
#include <time.h>
#include <optional>
#include "Chunk.h"

///////////////////////////////////////////////////////////
/// @brief World
///
class World
{
private:
    int _width;
    int _height;
    std::vector<Chunk> _chunks;
public:
    const int CHUNKSIZE;

    World(int chunkSize);
    ~World();

    int getCurrentWorldWidth() { return _width; }
    int getCurrentWorldHeight() { return _height; }

    std::optional<Chunk> GetChunkAt(int x, int y);

};

#endif  // __WORLD_H__
