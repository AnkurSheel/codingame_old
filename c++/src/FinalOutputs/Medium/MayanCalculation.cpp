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
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

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

#include <math.h>
#include <sstream>
#include <vector>
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
  void cCustom2DArray<Type>::Reset()
  {
    if (m_array != nullptr)
    {
      memset(m_array, -1, GetSize() * sizeof(Type));
    }
  }
}
#endif  // Custom2DArray_H__


using namespace std;
using namespace MayanCalculation;
using namespace Common;

cCustom2DArray<string> mayanNumbers;
void MayanCalculation::main()
{
  int widthOfNumeral;
  int heightOfNumeral;
  cin >> widthOfNumeral >> heightOfNumeral;
  cin.ignore();

  mayanNumbers.Init(20, heightOfNumeral, false);
  for (int i = 0; i < heightOfNumeral; i++)
  {
    int currentNumber = 0;
    string numeral;
    cin >> numeral;
    cin.ignore();
    for (int  j = 0; j < numeral.length(); j++)
    {
      mayanNumbers.GetElement(currentNumber, i).push_back(numeral[j]);
      if ((j + 1) % widthOfNumeral == 0)
      {
        currentNumber++;
      }
    }
  }

  int firstNumber = GetIntegerFromMayanNumber(heightOfNumeral);
  int secondNumber = GetIntegerFromMayanNumber(heightOfNumeral);

  string operation;
  cin >> operation;
  cin.ignore();

  ll result;
  if (operation == "+")
  {
    result = firstNumber + secondNumber;
  }
  else if (operation == "-")
  {
    result = firstNumber - secondNumber;
  }
  else if (operation == "*")
  {
    result = (ll)firstNumber * secondNumber;
  }
  else if (operation == "/")
  {
    result = firstNumber / secondNumber;
  }


  vector<int> mayanResult;
  ConvertToMayanNumber(result, mayanResult);

  if (mayanResult.size() == 0)
  {
    mayanResult.push_back(0);
  }

  for (int i = mayanResult.size() - 1; i >= 0; i--)
  {
    for (int j = 0; j < heightOfNumeral; j++)
    {
      cout << mayanNumbers.GetElement(mayanResult[i],j) << endl;
    }
  }
}

int MayanCalculation::GetIntegerFromMayanNumber(int heightOfMayanNumber)
{
  int bitField = 0;
  int totalSum = 0;
  int sum = 0;

  int numberOfLines;
  cin >> numberOfLines; cin.ignore();
  
  int numberOfDigits = numberOfLines / heightOfMayanNumber;

  int multiplier = pow(20, numberOfDigits - 1);

  for (int i = 0; i < numberOfLines; i++)
  {
    int heightIndex = i % heightOfMayanNumber;
    if (i > 0 && heightIndex == 0)
    {
      totalSum += (sum * multiplier);
      multiplier /= 20;
      sum = 0;
      bitField = 0;
    }
    string numberLine;
    cin >> numberLine; cin.ignore();
    for (int j = 0; j < 20; j++)
    {
      if (heightIndex == 0)
      {
        if (mayanNumbers.GetElement(j, heightIndex) == numberLine)
        {
          SetBit(bitField, j);
          sum += j;
        }
      }
      else
      {
        if (IsBitSet(bitField, j))
        {
          if (mayanNumbers.GetElement(j, heightIndex) != numberLine)
          {
            ClearBit(bitField, j);
            sum -= j;
          }
        }
      }
    }
  }
  totalSum += (sum * multiplier);
  return totalSum;
}

void MayanCalculation::ConvertToMayanNumber(ll number, std::vector<int>& convertedNumber)
{
  ll remainder = 0;
  ll tempNumber = number;
  convertedNumber.clear();

  tempNumber = number;
  while (tempNumber > 0)
  {
    remainder = tempNumber % 20;
    tempNumber = tempNumber / 20;
    convertedNumber.push_back(remainder);
  }
}

using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  MayanCalculation::main();

}

