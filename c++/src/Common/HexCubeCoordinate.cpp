#include "HexCubeCoordinate.h"

using namespace HexCubeCoordinate;
using namespace std;
const vector<Hex> hexDirections = {Hex(1, -1, 0), Hex(1, 0, -1), Hex(0, 1, -1),
                                   Hex(-1, 1, 0), Hex(-1, 0, 1), Hex(0, -1, 1)};

//  *******************************************************************************************************************
cPoint<int> HexCubeCoordinate::roffsetFromCube(int offset, Hex cube)
{
  int row = cube.x + int((cube.z + offset * (cube.z & 1)) / 2);
  int col = cube.z;
  return cPoint<int>(row, col);
}

//  *******************************************************************************************************************
Hex HexCubeCoordinate::roffsetToCube(int offset, int row, int col)
{
  int x = row - int((col + offset * (col & 1)) / 2);
  int z = col;
  int y = -x - z;
  return Hex(x, y, z);
}

//  *******************************************************************************************************************
int HexCubeCoordinate::rOddOffsetDistance(const cPoint<double>& pointA, const cPoint<double>& pointB)
{
  Hex ac = roffsetToCube(ODD, round(pointA.GetX()), round(pointA.GetY()));
  Hex bc = roffsetToCube(ODD, round(pointB.GetX()), round(pointB.GetY()));
  return HexDistance(ac, bc);
}

//  *******************************************************************************************************************
int HexCubeCoordinate::HexDistance(Hex a, Hex b)
{
  return HexLength(HexSubtract(a, b));
}

//  *******************************************************************************************************************
int HexCubeCoordinate::HexLength(Hex hex)
{
  return int((abs(hex.x) + abs(hex.y) + abs(hex.z)) / 2);
}

//  *******************************************************************************************************************
Hex HexCubeCoordinate::HexSubtract(Hex a, Hex b)
{
  return Hex(a.x - b.x, a.y - b.y, a.z - b.z);
}

Hex HexCubeCoordinate::HexDirection(int direction)
{
  return hexDirections[direction];
}

Hex HexCubeCoordinate::HexNeighbor(Hex hex, int direction)
{
  return HexAdd(hex, HexDirection(direction));
}

Hex HexCubeCoordinate::HexNeighbor(Hex hex, int direction, int turns)
{
  for (int i = 0; i < turns; ++i)
  {
    hex = HexNeighbor(hex, direction);
  }
  return hex;
}

Hex HexCubeCoordinate::HexAdd(Hex a, Hex b)
{
  return Hex(a.x + b.x, a.y + b.y, a.z + b.z);
}
