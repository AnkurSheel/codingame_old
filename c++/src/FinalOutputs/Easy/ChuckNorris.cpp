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

#ifndef ChuckNorris_H__
#define ChuckNorris_H__

namespace ChuckNorris
{
  void main();
}

#endif // ChuckNorris_H__



#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAXBITS = 7;
string AsciiToBinary(int asciiCode)
{
  string binary(MAXBITS, '0');
  int i = MAXBITS - 1;
  while (asciiCode > 0)
  {
    binary[i--] = ((asciiCode % 2) == 0) ? '0' : '1';
    asciiCode /= 2;
  }
  return binary;
}

void ChuckNorris::main()
{
  string message = "";
  getline(cin, message);

  string binary = "";
  ostringstream chuckCode;
  for (int i = 0; i < message.length(); i++)
  {
    binary += AsciiToBinary(message[i]);
  }
  char currentBit = binary[0];
  int count = 0;
  int i = 0;
  while (i < binary.length())
  {
    while (i < binary.length() && binary[i] == currentBit)
    {
      i++;
      count++;
    }
    if (currentBit == '1')
    {
      chuckCode << '0';
      currentBit = '0';
    }
    else
    {
      chuckCode << "00";
      currentBit = '1';
    }
    chuckCode << " ";
    for (int k = 0; k < count; k++)
    {
      chuckCode << "0";
    }
    if (i < binary.length())
    {
      chuckCode << " ";
    }
    count = 0;
  }

  cout << chuckCode.str() << endl;
}



using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  ChuckNorris::main();

}

