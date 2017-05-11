#include "ThereIsNoSpoonEpisode1.h"
#include <sstream>
#include <vector>
#include "../Common/Custom2DArray.h"
#include "../Common/Includes.h"

using namespace std;
using namespace ThereIsNoSpoonEpisode1;
using namespace Common;

static cCustom2DArray cells;
static stringstream output;

void AddRightNode(int currentRow, int rightIndex, int width)
{
  while (rightIndex < width && cells.GetElement(currentRow, rightIndex) != 1)
  {
    rightIndex++;
  }
  if (rightIndex < width)
  {
    output << rightIndex << " " << currentRow << " ";
  }
  else
  {
    output << "-1 -1 ";
  }
}

void AddBottomNode(int currentColumn, int bottomIndex, int height)
{
  while (bottomIndex < height && cells.GetElement(bottomIndex, currentColumn) != 1)
  {
    bottomIndex++;
  }
  if (bottomIndex < height)
  {
    output << currentColumn << " " << bottomIndex << " ";
  }
  else
  {
    output << "-1 -1 ";
  }
}
void ThereIsNoSpoonEpisode1::main()
{
  int width;
  cin >> width;
  cin.ignore();
  int height;
  cin >> height;
  cin.ignore();

  cells.Init(height, width);

  for (int i = 0; i < height; i++)
  {
    string line;
    getline(cin, line);
    for (int j = 0; j < width; j++)
    {
      cells.SetElement(i, j, ((line[j] == '0') ? 1 : 0));
    }
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      output.str("");
      output.clear();
      if (cells.GetElement(i, j) == 0)
      {
        continue;
      }
      output << j << " " << i << " ";
      AddRightNode(i, j + 1, width);
      AddBottomNode(j, i + 1, height);

      cout << output.str() << endl;
    }
  }
}
