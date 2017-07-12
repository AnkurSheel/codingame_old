#ifndef Custom2DArray_H__
#define Custom2DArray_H__

#include <cassert>
#include <cstring>
#include <iomanip>

namespace Common
{
  template <class Type>
  class cCustom2DArray
  {
  public:
    cCustom2DArray();
    ~cCustom2DArray();

    void Init(int rows, int columns, bool reset = true);
    const Type& GetElement(int row, int column) const;
    Type& GetElement(int row, int column);
    void SetElement(int row, int column, const Type& value);
    void Reset(const Type& value);

  private:
    void Reset();
    int GetIndex(int row, int column) const { return row * m_numberOfColumns + column; }
    int GetSize() const { return m_numberOfRows * m_numberOfColumns; }

  private:
    Type* m_array;
    int m_numberOfRows;
    int m_numberOfColumns;
  };

  template <class Type>
  cCustom2DArray<Type>::cCustom2DArray()
    : m_array(nullptr)
    , m_numberOfRows(0)
    , m_numberOfColumns(0)
  {
  }

  template <class Type>
  cCustom2DArray<Type>::~cCustom2DArray()
  {
    delete[] m_array;
    m_array = nullptr;
  }

  template <class Type>
  void cCustom2DArray<Type>::Init(int rows, int columns, bool reset)
  {
    if (rows != m_numberOfRows || columns != m_numberOfColumns || !reset)
    {
      if (m_array != nullptr)
      {
        delete[] m_array;
        m_array = nullptr;
      }

      m_numberOfRows = rows;
      m_numberOfColumns = columns;

      m_array = new Type[GetSize()];
    }
    if (reset)
    {
      Reset();
    }
  }

  template <class Type>
  const Type& cCustom2DArray<Type>::GetElement(int row, int column) const
  {
    assert(row >= 0 && row < m_numberOfRows && column >= 0 && column < m_numberOfColumns);
    return m_array[GetIndex(row, column)];
  }

  template <class Type>
  Type& cCustom2DArray<Type>::GetElement(int row, int column)
  {
    assert(row >= 0 && row < m_numberOfRows && column >= 0 && column < m_numberOfColumns);
    return m_array[GetIndex(row, column)];
  }

  template <class Type>
  void cCustom2DArray<Type>::SetElement(int row, int column, const Type& value)
  {
    assert(row >= 0 && row < m_numberOfRows && column >= 0 && column < m_numberOfColumns);
    m_array[GetIndex(row, column)] = value;
  }

  template <class Type>
  void cCustom2DArray<Type>::Reset(const Type& value)
  {
    if (m_array != nullptr)
    {
      int size = GetSize();
      for (int i = 0; i < size; ++i)
      {
        m_array[i] = value;
      }
    }
  }

  template <class Type>
  void cCustom2DArray<Type>::Reset()
  {
    if (m_array != nullptr)
    {
      memset(m_array, -1, GetSize() * sizeof(Type));
    }
  }
}
#endif  // Custom2DArray_H__
