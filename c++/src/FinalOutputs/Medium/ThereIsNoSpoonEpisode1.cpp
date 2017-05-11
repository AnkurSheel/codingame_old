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
#define DEBUGPRINTSTDIN(format, ...) DEBUGPRINT(format, ##__VA_ARGS__)
#endif  //  _INPUT
#define MS0(m_x) memset(m_x, 0, sizeof(m_x))
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

#ifndef _ThereIsNoSpoonEpisode1_H__
#define _ThereIsNoSpoonEpisode1_H__

namespace ThereIsNoSpoonEpisode1
{
  void main();
}

#endif  // !_ThereIsNoSpoonEpisode1_H__

#include <sstream>
#include <vector>
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

#include <cstring>
#include <iomanip>

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

void Common::cCustom2DArray::Reset()
{
  if (m_array != nullptr)
  {
    memset(m_array, -1, GetSize() * sizeof(int));
  }
}

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


using namespace std;
using namespace ThereIsNoSpoonEpisode1;
using namespace Common;

static cCustom2DArray cells;
static stringstream output;

void AddRightNode(int currentRow, int rightIndex, int width)
{
  while (rightIndex < width && cells.GetElement(currentRow, rightIndex) != 1)
  {
    rightIndex++;
  }
  if (rightIndex < width)
  {
    output << rightIndex << " " << currentRow << " ";
  }
  else
  {
    output << "-1 -1 ";
  }
}

void AddBottomNode(int currentColumn, int bottomIndex, int height)
{
  while (bottomIndex < height && cells.GetElement(bottomIndex, currentColumn) != 1)
  {
    bottomIndex++;
  }
  if (bottomIndex < height)
  {
    output << currentColumn << " " << bottomIndex << " ";
  }
  else
  {
    output << "-1 -1 ";
  }
}
void ThereIsNoSpoonEpisode1::main()
{
  int width;
  cin >> width;
  cin.ignore();
  int height;
  cin >> height;
  cin.ignore();

  cells.Init(height, width);

  for (int i = 0; i < height; i++)
  {
    string line;
    getline(cin, line);
    for (int j = 0; j < width; j++)
    {
      cells.SetElement(i, j, ((line[j] == '0') ? 1 : 0));
    }
  }

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j++)
    {
      output.str("");
      output.clear();
      if (cells.GetElement(i, j) == 0)
      {
        continue;
      }
      output << j << " " << i << " ";
      AddRightNode(i, j + 1, width);
      AddBottomNode(j, i + 1, height);

      cout << output.str() << endl;
    }
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  ThereIsNoSpoonEpisode1::main();

}

