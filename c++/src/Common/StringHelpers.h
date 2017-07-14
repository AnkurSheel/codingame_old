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
