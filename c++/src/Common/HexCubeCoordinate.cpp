#include "HexCubeCoordinate.h"

using namespace HexCubeCoordinate;
using namespace std;

const int EVEN = 1;
const int ODD = -1;

const vector<Hex> hexDirections = {Hex(1, -1, 0), Hex(1, 0, -1), Hex(0, 1, -1),
                                   Hex(-1, 1, 0), Hex(-1, 0, 1), Hex(0, -1, 1)};

//  *******************************************************************************************************************
cPoint<int> HexCubeCoordinate::roffsetFromCube(int offset, const Hex& cube)
{
  int row = cube.x + int((cube.z + offset * (cube.z & 1)) / 2);
  int col = cube.z;
  return cPoint<int>(row, col);
}

Hex HexCubeCoordinate::rOddOffsetToCube(int x, int y)
{
  return roffsetToCube(ODD, x, y);
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
int HexCubeCoordinate::rOddOffsetDistance(int xPos1, int yPos1, int xPos2, int yPos2)
{
  Hex ac = roffsetToCube(ODD, xPos1, yPos1);
  Hex bc = roffsetToCube(ODD, xPos2, yPos2);
  return HexDistance(ac, bc);
}

//  *******************************************************************************************************************
int HexCubeCoordinate::HexDistance(const Hex& a, const Hex& b)
{
  return HexLength(HexSubtract(a, b));
}

//  *******************************************************************************************************************
int HexCubeCoordinate::HexLength(const Hex& hex)
{
  return int((abs(hex.x) + abs(hex.y) + abs(hex.z)) / 2);
}

//  *******************************************************************************************************************
Hex HexCubeCoordinate::HexSubtract(const Hex& a, const Hex& b)
{
  return Hex(a.x - b.x, a.y - b.y, a.z - b.z);
}

//  *******************************************************************************************************************
cPoint<int> HexCubeCoordinate::rOddOffsetFromCube(const Hex& cube)
{
  return roffsetFromCube(ODD, cube);
}

Hex HexCubeCoordinate::HexDirection(int direction)
{
  return hexDirections[direction];
}

Hex HexCubeCoordinate::HexNeighbor(const Hex& hex, int direction)
{
  return HexAdd(hex, HexDirection(direction));
}

Hex HexCubeCoordinate::HexOddNeighbor(int x, int y, int direction, int turns)
{
  Hex temp = rOddOffsetToCube(x, y);
  for (int i = 0; i < turns; ++i)
  {
    temp = HexNeighbor(temp, direction);
  }
  return temp;
}

Hex HexCubeCoordinate::HexAdd(const Hex& a, const Hex& b)
{
  return Hex(a.x + b.x, a.y + b.y, a.z + b.z);
}
