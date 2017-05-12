#include "Temperatures.h"
#include "../Common/Includes.h"

using namespace std;

void Temperatures::main()
{
  int numberOfTemperatures;
  cin >> numberOfTemperatures;
  cin.ignore();
  string temperatures;
  getline(cin, temperatures);

  char* pEnd;
  long closestToZero = (strtol(temperatures.c_str(), &pEnd, 0));
  while (pEnd[0] != '\0')
  {
    long value = strtol(pEnd, &pEnd, 0);
    if (abs(closestToZero) == abs(value) && closestToZero < 0 && value > 0)
    {
      closestToZero = abs(value);
    }
    else if (abs(closestToZero) > abs(value))
    {
      closestToZero = value;
    }
  }

  cout << closestToZero << endl;
}