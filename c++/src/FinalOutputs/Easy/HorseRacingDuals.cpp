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

#ifndef HorseRacingDuals_H__
#define HorseRacingDuals_H__

namespace HorseRacingDuals
{
  void main();
}
#endif  // HorseRacingDuals_H__


using namespace std;

struct classcomp
{
  bool operator()(const int& lhs, const int& rhs) const { return lhs < rhs; }
};

void HorseRacingDuals::main()
{
  int numberOfHorses;
  cin >> numberOfHorses;
  cin.ignore();

  std::multiset<int, classcomp> horseStrengths;
  for (int i = 0; i < numberOfHorses; i++)
  {
    int Pi;
    cin >> Pi;
    cin.ignore();
    horseStrengths.insert(Pi);
  }

  int bestDifference = numeric_limits<int>::max();
  auto previousStrength = horseStrengths.begin();
  auto currentStrength = previousStrength;
  currentStrength++;
  while (currentStrength != horseStrengths.end())
  {
    int difference = abs(*currentStrength - *previousStrength);
    if (difference < bestDifference)
    {
      bestDifference = difference;
    }
    previousStrength = currentStrength;
    currentStrength++;
  }
  cout << bestDifference << endl;
}



using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  HorseRacingDuals::main();

}
