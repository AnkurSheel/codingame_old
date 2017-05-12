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


#ifndef _StockExchangeLosses_H__
#define _StockExchangeLosses_H__

namespace StockExchangeLosses
{
  void main();
}

#endif  // !_StockExchangeLosses_H__


using namespace std;
using namespace StockExchangeLosses;

void StockExchangeLosses::main()
{
  int numberOfStockValues;
  cin >> numberOfStockValues;
  cin.ignore();

  int maxValue = std::numeric_limits<int>::min();
  int minValue = std::numeric_limits<int>::max();
  int difference = 0;

  for (int i = 0; i < numberOfStockValues; i++)
  {
    int stockValue;
    cin >> stockValue;
    cin.ignore();
    if (stockValue > maxValue)
    {
      maxValue = stockValue;
      minValue = std::numeric_limits<int>::max();
    }
    if (stockValue < minValue)
    {
      minValue = stockValue;
      int newdifference = maxValue - minValue;
      if (newdifference > difference)
      {
        difference = newdifference;
      }
    }
  }
  difference = -difference;
  cout << difference << endl;
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  StockExchangeLosses::main();

}

