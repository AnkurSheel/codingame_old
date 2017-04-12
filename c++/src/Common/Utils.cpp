#include "Utils.h"

void ConvertNumber(ll number, int newBase, std::vector<int>& convertedNumber)
{
  ll remainder = 0;
  ll tempNumber = number;
  convertedNumber.clear();

  tempNumber = number;
  while (tempNumber > 0)
  {
    remainder = tempNumber % newBase;
    tempNumber = tempNumber / newBase;
    convertedNumber.push_back(remainder);
  }
}
