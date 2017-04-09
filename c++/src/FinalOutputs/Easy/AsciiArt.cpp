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

#ifndef _AsciiArt_H__
#define _AsciiArt_H__

namespace AsciiArt
{
  void main();
}

#endif  // !_AsciiArt_H__

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


using namespace std;
using namespace AsciiArt;

void AsciiArt::main()
{
  vector<string> rows;

  int widthOfLetter;
  cin >> widthOfLetter;
  cin.ignore();
  int heightOfLetter;
  cin >> heightOfLetter;
  cin.ignore();
  string text;
  getline(cin, text);

  for (int i = 0; i < heightOfLetter; i++)
  {
    string row;
    getline(cin, row);
    rows.push_back(row);
  }

  vector<string> output(heightOfLetter);
  for (int i = 0; i < text.length(); i++)
  {
    int startingIndex = 0;
    if (text[i] >= 'a' && text[i] <= 'z')
    {
      text[i] = toupper(text[i]);
    }
    int ascii = text[i];

    // if not a letter get index for ? which is after Z
    if (ascii < 'A' || ascii > 'Z')
    {
      ascii = 'Z' + 1;
    }

    ascii -= 'A';

    startingIndex = ascii * widthOfLetter;

    for (int j = 0; j < heightOfLetter; j++)
    {
      for (int k = 0; k < widthOfLetter; k++)
      {
        output[j] += rows[j][startingIndex + k];
      }
    }
  }

  for (int j = 0; j < heightOfLetter; j++)
  {
    cout << output[j] << endl;
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");

  AsciiArt::main();

}

