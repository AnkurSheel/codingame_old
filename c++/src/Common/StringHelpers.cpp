#include "StringHelpers.h"
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
