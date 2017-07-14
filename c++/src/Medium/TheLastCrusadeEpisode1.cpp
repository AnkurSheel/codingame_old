#include "TheLastCrusadeEpisode1.h"
#include "../Common/Includes.h"

using namespace std;

void TheLastCrusadeEpisode1::main()
{
  int numberOfColumns;
  int numberOfRows;
  cin >> numberOfColumns >> numberOfRows;
  cin.ignore();
  for (int i = 0; i < numberOfRows; i++)
  {
    string gridLine;
    getline(cin, gridLine);
  }
  int exitXCoordinate;
  cin >> exitXCoordinate;
  cin.ignore();

  // game loop
  while (true)
  {
    int column;
    int row;
    string entranceDirection;
    cin >> column >> row >> entranceDirection;
    cin.ignore();
    int newColumn = column;
    int newRow = row;
    cout << newColumn << " " << newRow << endl;
  }
}