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


#ifndef _PowerofThorEpisode1_H__
#define _PowerofThorEpisode1_H__

namespace PowerofThorEpisode1
{
  void main();
}
#endif // !_PowerofThorEpisode1_H__



using namespace std;

void PowerofThorEpisode1::main()
{
  int lightX;
  int lightY;
  int initialThorX;
  int initialThorY;
  cin >> lightX >> lightY >> initialThorX >> initialThorY;
  cin.ignore();

  int posX = initialThorX;
  int posY = initialThorY;
  string direction;

  while (1)
  {
    int remainingTurns;
    cin >> remainingTurns;
    cin.ignore();

    direction = "";

    if (posY > lightY)
    {
      direction = "N";
      posY--;
    }
    else if (posY < lightY)
    {
      direction = "S";
      posY++;
    }

    if (posX > lightX)
    {
      direction.append("W");
      posX--;
    }
    else if (posX < lightX)
    {
      direction.append("E");
      posX++;
    }

    cout << direction << endl;
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");

  PowerofThorEpisode1::main();

}

