#include "World.h"

World::World(int chunkSize)
{
    World::CHUNKSIZE = chunkSize;

    // Intialize Rand
    srand (time(NULL));
    
    _chunks.push_back(new Chunk(0, 0));
}

World::~World()
{
    while (!_chunks.empty())
    {
        _chunks.pop_back();
    }
    
}

Chunk* World::getChunkAt(int worldX, int worldY){
    for (std::vector<Chunk*>::iterator it = _chunks.begin(); it != _chunks.end(); ++it){
        Chunk* c = *it;
        if (worldX >= c->getWorldX() && worldX < c->getWorldX() + World::CHUNKSIZE &&
            worldY >= c->getWorldY() && worldY < c->getWorldY() + World::CHUNKSIZE){
            return c;
        }
    }
    return nullptr;
}