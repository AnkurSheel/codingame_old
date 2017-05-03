#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include "Includes.h"

namespace Utils
{
  inline bool isEqual(const double a, const double b)
  {
    if (fabs(a - b) < 0.0001)
    {
      return true;
    }

    return false;
  }

  template <typename Interface>
  inline void SafeDeleteArray(Interface** ppArrayToDelete)
  {
    if (*ppArrayToDelete != NULL)
    {
      delete[](*ppArrayToDelete);
      (*ppArrayToDelete) = NULL;
    }
  }

  template <typename Interface>
  inline void SafeDelete(Interface** ppInterfaceToDelete)
  {
    if (*ppInterfaceToDelete != NULL)
    {
      delete (*ppInterfaceToDelete);
      (*ppInterfaceToDelete) = NULL;
    }
  }

  void ConvertNumber(ll number, int newBase, std::vector<int>& convertedNumber);

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
