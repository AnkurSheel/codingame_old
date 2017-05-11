#ifndef _BitOperations_H__
#define _BitOperations_H__

#include <string>

namespace Common
{
  template<class T>
  void SetBit(T& bitField, const int bit)
  {
    bitField |= (1 << bit);
  }

  template<class T>
  void ClearBit(T& bitField, const int bit)
  {
    bitField &= ~(1 << bit);
  }

  template<class T>
  bool IsBitSet(const T bitField, const int bit)
  {
    return (bitField >> bit) & 1;
  }
}
#endif  // _BitOperations_H__
