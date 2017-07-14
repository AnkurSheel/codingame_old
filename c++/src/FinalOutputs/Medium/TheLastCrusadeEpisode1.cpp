#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#define DEBUGPRINT(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#ifdef _INPUT
#define DEBUGPRINTSTDIN(format, ...)                                                                                   \
  fprintf(stderr, "IN\n");                                                                                             \
  fprintf(stderr, format, ##__VA_ARGS__);                                                                              \
  fprintf(stderr, "/IN\n")
#else
#define DEBUGPRINTSTDIN(format, ...)
#endif  //  _INPUT
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

#ifndef TheLastCrusadeEpisode1_H__
#define TheLastCrusadeEpisode1_H__
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


namespace TheLastCrusadeEpisode1
{
  void GetNextPos(int gridType, const std::string& entrancePoint,
                  int& newColumn, int& newRow);
  void main();
}

#endif  // !TheLastCrusadeEpisode1_H__

#include <vector>
#ifndef StringHelpers_H__
#define StringHelpers_H__

#include <vector>

namespace Common
{
  class cStringHelpers
  {
  public:
    static void Tokenize(const std::string& stringToTokenize, const std::string& delimiters, std::vector<std::string>& parts);
  };
}

#endif  // !StringHelpers_H__

#include <vector>

using namespace std;

void Common::cStringHelpers::Tokenize(const string& stringToTokenize, const string& delimiters, vector<string>& parts)
{
  size_t iStartIndex = 0;
  while (iStartIndex < stringToTokenize.length())
  {
    size_t nextIndex = stringToTokenize.find_first_of(delimiters, iStartIndex);
    if (nextIndex == string::npos)
    {
      nextIndex = stringToTokenize.length();
    }
    if (iStartIndex != nextIndex)
    {
      parts.push_back(stringToTokenize.substr(iStartIndex, nextIndex - iStartIndex));
    }
    else
    {
      parts.push_back("");
    }
    iStartIndex = nextIndex + 1;
  }
}


using namespace std;
using namespace Common;

void TheLastCrusadeEpisode1::GetNextPos(int gridType, const string& entrancePoint, int& newColumn, int& newRow)
{
  switch (gridType)
  {
    case 1:
    case 3:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
      ++newRow;
      break;
    case 2:
    case 6:
      if (entrancePoint == "LEFT")
      {
        ++newColumn;
      }
      else
      {
        --newColumn;
      }
      break;
    case 4:
      if (entrancePoint == "TOP")
      {
        --newColumn;
      }
      else
      {
        ++newRow;
      }

      break;
    case 5:
      if (entrancePoint == "TOP")
      {
        ++newColumn;
      }
      else
      {
        ++newRow;
      }
      break;
    case 10:
      --newColumn;
      break;
    case 11:
      ++newColumn;
      break;
  }
}

void TheLastCrusadeEpisode1::main()
{
  int numberOfColumns;
  int numberOfRows;
  cin >> numberOfColumns >> numberOfRows;
  cin.ignore();
  DEBUGPRINTSTDIN("%d %d\n", numberOfColumns, numberOfRows);
  cCustom2DArray<int> grid;
  grid.Init(numberOfRows, numberOfColumns);
  for (int i = 0; i < numberOfRows; i++)
  {
    string gridLine;
    getline(cin, gridLine);
    DEBUGPRINTSTDIN("%s\n", gridLine.data());
    vector<string> parts;
    cStringHelpers::Tokenize(gridLine, " ", parts);

    char* pEnd;
    for (int j = 0; j < parts.size(); ++j)
    {
      grid.SetElement(i, j, (strtol(parts[j].c_str(), &pEnd, 0)));
    }
  }

  int exitXCoordinate;  // not useful for this first mission, but must be read).
  cin >> exitXCoordinate;
  DEBUGPRINTSTDIN("%d\n", exitXCoordinate);
  cin.ignore();

  // game loop
  while (true)
  {
    int row;
    int column;
    string entrancePoint;
    cin >> column >> row >> entrancePoint;
    cin.ignore();
    DEBUGPRINTSTDIN("%d %d %s\n", column, row, entrancePoint.data());
    int gridType = grid.GetElement(row, column);
    DEBUGPRINT("%d %s\n", gridType, entrancePoint.data());

    int newColumn = column;
    int newRow = row;

    GetNextPos(gridType, entrancePoint, newColumn, newRow);
    cout << newColumn << " " << newRow << endl;
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  TheLastCrusadeEpisode1::main();

}

