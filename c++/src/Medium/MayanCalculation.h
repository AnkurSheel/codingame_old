#ifndef _MayanCalculation_H__
#define _MayanCalculation_H__

#include <vector>

namespace MayanCalculation
{
  void main();
  int GetIntegerFromMayanNumber(int heightOfMayanNumber);
  void ConvertToMayanNumber(long long number, std::vector<int>& convertedNumber);
}

#endif  // !_MayanCalculation_H__
