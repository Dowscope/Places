#include "Chunk.h"

using namespace std;

Chunk::Chunk(int x, int y, int width) : 
    _x(x), _y(y), _width(width)
{
    for (size_t y = 0; y < _width; y++)
    {
        for (size_t x = 0; x < _width; x++)
        {
            _tiles.push_back(Tile(x, y, 1));
        }
    }
}

Chunk::~Chunk()
{
    _tiles.clear();
}

std::optional<Tile> Chunk::GetChunkTileAt(int x, int y)
{
    for (size_t i = 0; i < _tiles.size(); i++)
    {
        Tile t = _tiles[i];
        if (t.getX() == x && t.getY() == y)
        {
            return std::optional<Tile>(t);
        }
    }

  return std::nullopt;
}
