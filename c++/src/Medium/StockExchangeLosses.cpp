#include "StockExchangeLosses.h"
#include "./Common/Includes.h"

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