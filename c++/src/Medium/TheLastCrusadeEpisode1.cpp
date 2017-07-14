#include "TheLastCrusadeEpisode1.h"
#include <vector>
#include "../Common/Custom2DArray.h"
#include "../Common/Includes.h"
#include "../Common/StringHelpers.h"

using namespace std;
using namespace Common;

void TheLastCrusadeEpisode1::GetNextPos(int gridType, const string& entrancePoint, int& newColumn, int& newRow)
{
  switch (gridType)
  {
    case 1:
    case 3:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
      ++newRow;
      break;
    case 2:
    case 6:
      if (entrancePoint == "LEFT")
      {
        ++newColumn;
      }
      else
      {
        --newColumn;
      }
      break;
    case 4:
      if (entrancePoint == "TOP")
      {
        --newColumn;
      }
      else
      {
        ++newRow;
      }

      break;
    case 5:
      if (entrancePoint == "TOP")
      {
        ++newColumn;
      }
      else
      {
        ++newRow;
      }
      break;
    case 10:
      --newColumn;
      break;
    case 11:
      ++newColumn;
      break;
  }
}

void TheLastCrusadeEpisode1::main()
{
  int numberOfColumns;
  int numberOfRows;
  cin >> numberOfColumns >> numberOfRows;
  cin.ignore();
  DEBUGPRINTSTDIN("%d %d\n", numberOfColumns, numberOfRows);
  cCustom2DArray<int> grid;
  grid.Init(numberOfRows, numberOfColumns);
  for (int i = 0; i < numberOfRows; i++)
  {
    string gridLine;
    getline(cin, gridLine);
    DEBUGPRINTSTDIN("%s\n", gridLine.data());
    vector<string> parts;
    cStringHelpers::Tokenize(gridLine, " ", parts);

    char* pEnd;
    for (int j = 0; j < parts.size(); ++j)
    {
      grid.SetElement(i, j, (strtol(parts[j].c_str(), &pEnd, 0)));
    }
  }

  int exitXCoordinate;  // not useful for this first mission, but must be read).
  cin >> exitXCoordinate;
  DEBUGPRINTSTDIN("%d\n", exitXCoordinate);
  cin.ignore();

  // game loop
  while (true)
  {
    int row;
    int column;
    string entrancePoint;
    cin >> column >> row >> entrancePoint;
    cin.ignore();
    DEBUGPRINTSTDIN("%d %d %s\n", column, row, entrancePoint.data());
    int gridType = grid.GetElement(row, column);
    DEBUGPRINT("%d %s\n", gridType, entrancePoint.data());

    int newColumn = column;
    int newRow = row;

    GetNextPos(gridType, entrancePoint, newColumn, newRow);
    cout << newColumn << " " << newRow << endl;
  }
}
