#include "Chunk.h"


Chunk::Chunk(int worldX, int worldY):
    _worldX(worldX), _worldY(worldY)
{
    for (int y = 0; y < World::CHUNKSIZE; y++)
    {
        for (int x = 0; x < World::CHUNKSIZE; x++)
        {
            _tiles.push_back(new Tile(x, y, rand() % 2));
        }
    }
    
}

Chunk::~Chunk()
{
    while (!_tiles.empty())
    {
        _tiles.pop_back();
    }
    
    
}
