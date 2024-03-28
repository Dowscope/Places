#include "World.h"

World::World(int chunkSize): CHUNKSIZE(chunkSize)
{
    // Initialize Rand
    srand (time(NULL));
    
    // Setup initial world
    _chunks.push_back(Chunk(0, 0, chunkSize));
}

World::~World()
{
    _chunks.clear();
}

std::optional<Chunk> World::GetChunkAt(int x, int y)
{
    for (size_t i = 0; i < _chunks.size(); i++)
    {
        Chunk c = _chunks[i];
        if (c.getX() == x && c.getY() == y)
        {
            return std::optional<Chunk>(c);
        }
    }

    return std::nullopt;
}
