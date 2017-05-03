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

  int HexDistance(Hex a, Hex b);
  int HexLength(Hex hex);
  Hex HexSubtract(Hex a, Hex b);

  // rtype = pointy top
  cPoint<int> roffsetFromCube(int offset, Hex cube);
  Hex roffsetToCube(int offset, int x, int y);

  const int EVEN = 1;
  const int ODD = -1;

  int rOddOffsetDistance(const cPoint<double>& pointA, const cPoint<double>& pointB);
  Hex HexDirection(int direction);
  Hex HexNeighbor(Hex hex, int direction);
  Hex HexNeighbor(Hex hex, int direction, int turns);
  Hex HexAdd(Hex a, Hex b);
}
#endif  // HexCubeCoordinate_H__
