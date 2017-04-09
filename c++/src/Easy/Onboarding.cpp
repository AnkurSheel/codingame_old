#include "Onboarding.h"
#include "../Common/Includes.h"

using namespace std;
using namespace Onboarding;

void Onboarding::main()
{
  while (1)
  {
    string enemy1;
    cin >> enemy1;
    cin.ignore();
    int dist1;
    cin >> dist1;
    cin.ignore();
    string enemy2;
    cin >> enemy2;
    cin.ignore();
    int dist2;
    cin >> dist2;
    cin.ignore();

    if (dist1 < dist2)
    {
      cout << enemy1 << endl;
    }
    else
    {
      cout << enemy2 << endl;
    }
  }
}
