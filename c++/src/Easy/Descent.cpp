#include "Descent.h"
#include "..\Common\Includes.h"

using namespace std;

void Descent::main()
{
  while (1)
  {
    int maxHeight = -1;
    int index = -1;

    for (int i = 0; i < 8; i++)
    {
      int mountainHeight;
      cin >> mountainHeight;
      cin.ignore();
      if (maxHeight < mountainHeight)
      {
        maxHeight = mountainHeight;
        index = i;
      }
    }
    cout << index << endl;
  }
}