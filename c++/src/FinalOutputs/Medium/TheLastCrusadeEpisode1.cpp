#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#define DEBUGPRINT(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#ifdef _INPUT
#define DEBUGPRINTSTDIN(format, ...)                                                                                   \
  fprintf(stderr, "IN\n");                                                                                             \
  fprintf(stderr, format, ##__VA_ARGS__);                                                                              \
  fprintf(stderr, "/IN\n")
#else
#define DEBUGPRINTSTDIN(format, ...)
#endif  //  _INPUT
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

#ifndef TheLastCrusadeEpisode1_H__
#define TheLastCrusadeEpisode1_H__

namespace TheLastCrusadeEpisode1
{
  void main();
}

#endif  // !TheLastCrusadeEpisode1_H__


using namespace std;

void TheLastCrusadeEpisode1::main()
{
  int numberOfColumns;
  int numberOfRows;
  cin >> numberOfColumns >> numberOfRows;
  cin.ignore();
  for (int i = 0; i < numberOfRows; i++)
  {
    string gridLine;
    getline(cin, gridLine);
  }
  int exitXCoordinate;
  cin >> exitXCoordinate;
  cin.ignore();

  // game loop
  while (true)
  {
    int column;
    int row;
    string entranceDirection;
    cin >> column >> row >> entranceDirection;
    cin.ignore();
    int newColumn = column;
    int newRow = row;
    cout << newColumn << " " << newRow << endl;
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  TheLastCrusadeEpisode1::main();

}

