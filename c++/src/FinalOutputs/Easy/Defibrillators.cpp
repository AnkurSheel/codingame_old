#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define DEBUGPRINT(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#ifdef  _INPUT
#define DEBUGPRINTSTDIN(format, ...) \
  fprintf(stderr, "IN\n"); \
  fprintf(stderr, format, ##__VA_ARGS__); \
  fprintf(stderr, "/IN\n")
#else
#define DEBUGPRINTSTDIN(format, ...) DEBUGPRINT(format, ##__VA_ARGS__)
#endif //  _INPUT


#define MS0(m_x) memset(m_x, 0, sizeof(m_x))
#define SORT(a, n) sort(begin(a), begin(a) + n)
#define REVERSE(a, n) reverse(begin(a), begin(a) + n)
#define ll long long
#define sp system("pause")

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

#ifndef Defibrillators_H__
#define Defibrillators_H__

namespace Defibrillators
{
  void main();
}

#endif  // Defibrillators_H__


using namespace std;

struct DefibrillatorInfo
{
  string name;
  double longitude;
  double latitude;
};

//  *******************************************************************************************************************
void Tokenize(const string& stringToTokenize, const string& delimiters, vector<string>& parts)
{
  int iStartIndex = 0;
  int nextIndex;
  while (iStartIndex < stringToTokenize.length())
  {
    nextIndex = stringToTokenize.find_first_of(delimiters, iStartIndex);
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

//  *******************************************************************************************************************
double ConvertToDecimal(string decimalString)
{
  double value;
  int index = decimalString.find_first_of(',');
  char* pEnd;
  decimalString[index] = '.';
  return strtod(decimalString.c_str(), &pEnd);
}

//  *******************************************************************************************************************
void ParseInfo(string defibrillator, DefibrillatorInfo& info)
{
  cerr << defibrillator << endl;
  vector<string> parts;
  Tokenize(defibrillator, ";", parts);
  info.name = parts[1];
  info.longitude = ConvertToDecimal(parts[4]);
  info.latitude = ConvertToDecimal(parts[5]);
}

//  *******************************************************************************************************************
void Defibrillators::main()

{
  string longitude;
  cin >> longitude;
  cin.ignore();
  string latitude;
  cin >> latitude;
  cin.ignore();
  int numberOfDefibrillator;
  cin >> numberOfDefibrillator;
  cin.ignore();

  double myLongitude = ConvertToDecimal(longitude);
  double myLatitude = ConvertToDecimal(latitude);

  DefibrillatorInfo info;
  string bestDefibrillatorName;
  double bestDefibrillatorDistance = numeric_limits<double>::max();

  for (int i = 0; i < numberOfDefibrillator; i++)
  {
    string defibrillator;
    getline(cin, defibrillator);
    ParseInfo(defibrillator, info);
    double x = (info.longitude - myLongitude) * cos((info.latitude + myLatitude) * 0.5f);
    double y = info.latitude - myLatitude;
    double d = sqrt(((x * x) + (y * y))) * 6371;
    if (d < bestDefibrillatorDistance)
    {
      bestDefibrillatorName = info.name;
      bestDefibrillatorDistance = d;
    }
  }

  cout << bestDefibrillatorName << endl;
}



using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  Defibrillators::main();

}

