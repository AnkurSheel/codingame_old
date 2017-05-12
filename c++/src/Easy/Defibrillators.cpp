#include "Defibrillators.h"
#include <vector>
#include "../Common/Includes.h"

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
