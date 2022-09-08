#ifndef __TILE_H__
#define __TILE_H__

///////////////////////////////////////////////////////////
/// @brief Tile
///
class Tile
{
public:
    Tile(int x, int y, int tileType);
    ~Tile();

    int getX() { return _x; }
    int getY() { return _y; }
    int getTileType() { return _tileType; }

private:
    int _x, _y;
    int _tileType;
};

#endif  // __TILE_H__
