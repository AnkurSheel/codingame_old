#ifndef HexCubeCoordinate_H__
#define HexCubeCoordinate_H__

#include "Common/Point.h"

// http://www.redblobgames.com/grids/hexagons/implementation.html
namespace HexCubeCoordinate
{
  struct Hex
  {
    int x;
    int y;
    int z;
    Hex(int x_, int y_, int s_)
      : x(x_)
      , y(y_)
      , z(s_)
    {
    }

    Hex& operator=(const Hex& other)
    {
      x = other.x;
      y = other.y;
      z = other.z;
      return *this;
    }
  };

  int HexDistance(const Hex& a, const Hex& b);
  int HexLength(const Hex& hex);
  Hex HexSubtract(const Hex& a, const Hex& b);

  // rtype = pointy top
  cPoint<int> rOddOffsetFromCube(const Hex& cube);
  cPoint<int> roffsetFromCube(int offset, const Hex& cube);
  Hex rOddOffsetToCube(int x, int y);
  Hex roffsetToCube(int offset, int x, int y);

  int rOddOffsetDistance(int xPos1, int yPos1, int xPos2, int yPos2);
  Hex HexDirection(int direction);
  Hex HexNeighbor(const Hex& hex, int direction);
  Hex HexOddNeighbor(int x, int y, int direction, int turns);
  Hex HexAdd(const Hex& a, const Hex& b);
}
#endif  // HexCubeCoordinate_H__
