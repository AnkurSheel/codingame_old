#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include "Includes.h"

namespace Common
{
  inline bool isEqual(const double a, const double b)
  {
    if (fabs(a - b) < 0.0001)
    {
      return true;
    }

    return false;
  }

  template <typename T>
  void Clamp(T& val, const T& min, const T& max)
  {
    if (val < min)
    {
      val = min;
    }
    else if (val > max)
    {
      val = max;
    }
  }
}
#endif  // !_UTILS_H
