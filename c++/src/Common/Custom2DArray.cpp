#include "Custom2DArray.h"
#include <cstring>
#include <iomanip>
#include "Includes.h"

using namespace std;

Common::cCustom2DArray::cCustom2DArray()
  : m_array(nullptr)
  , m_numberOfRows(0)
  , m_numberOfColumns(0)
{
}

Common::cCustom2DArray::~cCustom2DArray()
{
  delete[] m_array;
  m_array = nullptr;
}

//  *******************************************************************************************************************
void Common::cCustom2DArray::Init(int rows, int columns)
{
  if (rows != m_numberOfRows || columns != m_numberOfColumns)
  {
    if (m_array != nullptr)
    {
      delete[] m_array;
      m_array = nullptr;
    }

    m_numberOfRows = rows;
    m_numberOfColumns = columns;

    m_array = new int[GetSize()];
  }
  Reset();
}

//  *******************************************************************************************************************
void Common::cCustom2DArray::Reset()
{
  if (m_array != nullptr)
  {
    memset(m_array, -1, GetSize() * sizeof(int));
  }
}

//  *******************************************************************************************************************
void Common::cCustom2DArray::PrintArray(const string& first, const string& second)
{
  int width = 4;
  for (int i = 0; i < first.length(); i++)
  {
    cout << setw(width) << first[i];
  }
  int j = 0;
  for (int i = 0; i < GetSize(); i++)
  {
    if (i % (m_numberOfRows) == 0)
    {
      cout << "\n";
      if (j < second.length())
      {
        cout << second[j];
        j++;
        width = 3;
      }
    }
    else
    {
      width = 4;
    }
    cout << setw(width) << m_array[i];
  }
  cout << "\n";
}
