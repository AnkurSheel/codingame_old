#ifndef _MemoryUtils_H__
#define _MemoryUtils_H__

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

#endif  // !_MemoryUtils_H__
