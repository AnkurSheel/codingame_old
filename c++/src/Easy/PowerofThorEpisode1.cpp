#include "PowerofThorEpisode1.h"
#include "..\Common\Includes.h"

using namespace std;

void PowerofThorEpisode1::main()
{
  int lightX;
  int lightY;
  int initialThorX;
  int initialThorY;
  cin >> lightX >> lightY >> initialThorX >> initialThorY;
  cin.ignore();

  int posX = initialThorX;
  int posY = initialThorY;
  string direction;

  while (1)
  {
    int remainingTurns;
    cin >> remainingTurns;
    cin.ignore();

    direction = "";

    if (posY > lightY)
    {
      direction = "N";
      posY--;
    }
    else if (posY < lightY)
    {
      direction = "S";
      posY++;
    }

    if (posX > lightX)
    {
      direction.append("W");
      posX--;
    }
    else if (posX < lightX)
    {
      direction.append("E");
      posX++;
    }

    cout << direction << endl;
  }
}