#include "MayanCalculation.h"
#include <math.h>
#include <sstream>
#include <vector>
#include "../Common/BitOperations.h"
#include "../Common/Custom2DArray.h"
#include "../Common/Includes.h"

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