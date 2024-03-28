#ifndef __CHUNK_H__
#define __CHUNK_H__

///////////////////////////////////////////////////////////
/// @brief Chunk
///

#include <vector>
#include <optional>
#include "Tile.h"

class Chunk
{
public:
    Chunk(int x, int y, int width);
    ~Chunk();

    int getX() { return _x; }
    int getY() { return _y; }
    std::optional<Tile> GetChunkTileAt(int x, int y);

private:
    int _width, _x, _y;
    std::vector<Tile> _tiles;
};

#endif  // __CHUNK_H__
