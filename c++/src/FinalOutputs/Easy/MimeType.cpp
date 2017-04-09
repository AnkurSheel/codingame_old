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

#ifndef MimeType_H__
#define MimeType_H__

namespace MimeType
{
  void main();
}
#endif  // MimeType_H__

#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
string GetExtension(const string& fileName)
{
  int index = fileName.find_last_of('.');
  if (index != string::npos)
  {
    return fileName.substr(index + 1, fileName.length() - index - 1);
  }
  return "";
}

void MimeType::main()
{
  int numberOfElements;
  cin >> numberOfElements;
  cin.ignore();
  int numberOfFileNames;
  cin >> numberOfFileNames;
  cin.ignore();
  map<string, string> typeMap;
  string output;

  for (int i = 0; i < numberOfElements; i++)
  {
    string fileExtension;
    string mimeType;
    cin >> fileExtension >> mimeType;
    cin.ignore();
    std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(), ::tolower);

    typeMap.insert(std::pair<string, string>(fileExtension, mimeType));
  }
  for (int i = 0; i < numberOfFileNames; i++)
  {
    string fileName;  // One file name per line.
    getline(cin, fileName);
    string extension = GetExtension(fileName);
    cerr << extension << endl;
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    auto it = typeMap.find(extension);
    if (it != typeMap.end())
    {
      output += it->second;
    }
    else
    {
      output += "UNKNOWN";
    }

    output += "\n";
  }

  cout << output << endl;
}



using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  MimeType::main();

}

