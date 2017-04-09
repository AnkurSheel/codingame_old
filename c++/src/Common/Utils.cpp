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

int RoundToInt(double value)
{
  // double roundedValue = 0;
  double roundedValue = 0;
  if (value > 0)
  {
    // roundedValue = floor(value + 0.5);
    roundedValue = round(value);
  }
  else
  {
    // roundedValue = ceil(value - 0.5) ;
    roundedValue = round(value);
  }
  return static_cast<int>(roundedValue);
}