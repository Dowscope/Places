#ifndef __CHUNK_H__
#define __CHUNK_H__

#include <vector>
#include <random>
#include "World.h"
#include "Tile.h"

///////////////////////////////////////////////////////////
/// @brief Chunk
///
class Chunk
{
public:
    Chunk(int worldX, int worldY);
    ~Chunk();

    int getWorldX() { return _worldX; }
    int getWorldY() { return _worldY; }
private:
    int _worldX, _worldY;
    std::vector<Tile*> _tiles;
};

#endif  // __CHUNK_H__
