#ifndef Custom2DArray_H__
#define Custom2DArray_H__

#include <string>

namespace Common
{
  class cCustom2DArray
  {
  public:
    cCustom2DArray();
    ~cCustom2DArray();

    int GetElement(int row, int column) const { return m_array[GetIndex(row, column)]; }
    void SetElement(int row, int column, int value) { m_array[GetIndex(row, column)] = value; }
    void Init(int rows, int columns);
    void PrintArray(const std::string& first, const std::string& second);

  private:
    void Reset();
    int GetIndex(int row, int column) const { return row + (m_numberOfRows * column); }
    int GetSize() const { return m_numberOfRows * m_numberOfColumns; }

  private:
    int* m_array;
    int m_numberOfRows;
    int m_numberOfColumns;
  };
}
#endif  // Custom2DArray_H__
