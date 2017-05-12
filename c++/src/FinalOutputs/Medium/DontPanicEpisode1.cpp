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
#define DEBUGPRINTSTDIN(format, ...) DEBUGPRINT(format, ##__VA_ARGS__)
#endif  //  _INPUT
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H


#ifndef _DontPanicEpisode1_H__
#define _DontPanicEpisode1_H__

namespace DontPanicEpisode1
{
  void main();
}

#endif  // !_DontPanicEpisode1_H__

#include <map>

using namespace std;
using namespace DontPanicEpisode1;

void DontPanicEpisode1::main()
{
  int numberOfFloors;
  int width;
  int numberOfRounds;
  int exitFloor;
  int exitPos;
  int numberOfTotalClones;
  int numberOfAdditionalElevators;  // ignore (always zero)
  int numberOfElevators;            // number of elevators
  cin >> numberOfFloors >> width >> numberOfRounds >> exitFloor >> exitPos >> numberOfTotalClones >>
      numberOfAdditionalElevators >> numberOfElevators;
  cin.ignore();

  DEBUGPRINT("nbFloors: %d, width: %d, nbRounds: %d, exitFloor: %d, exitPos: %d\n", numberOfFloors, width,
             numberOfRounds, exitFloor, exitPos);
  DEBUGPRINT("nbTotalClones: %d, nbAdditionalElevators: %d, nbElevators: %d\n", numberOfTotalClones,
             numberOfAdditionalElevators, numberOfElevators);

  map<int, int> elevators;
  for (int i = 0; i < numberOfElevators; i++)
  {
    int elevatorFloor;  // floor on which this elevator is found
    int elevatorPos;    // position of the elevator on its floor
    cin >> elevatorFloor >> elevatorPos;
    cin.ignore();
    DEBUGPRINT("elevatorFloor: %d, elevatorFloor: %d\n", elevatorFloor, elevatorPos);
    elevators[elevatorFloor] = elevatorPos;
  }

  // game loop
  while (1)
  {
    int cloneFloor;    // floor of the leading clone
    int clonePos;      // position of the leading clone on its floor
    string direction;  // direction of the leading clone: LEFT or RIGHT

    cin >> cloneFloor >> clonePos >> direction;
    cin.ignore();

    DEBUGPRINT("cloneFloor: %d, clonePos: %d, direction: %s\n", cloneFloor, clonePos, direction.c_str());

    string action = "WAIT";
    if (cloneFloor != -1)
    {
      int targetpos = exitPos;
      if (cloneFloor != exitFloor)
      {
        targetpos = elevators[cloneFloor];
      }

      if ((clonePos > targetpos && direction == "RIGHT") || (clonePos < targetpos && direction == "LEFT"))
      {
        action = "BLOCK";
      }
    }
    cout << action << endl;  // action: WAIT or BLOCK
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  DontPanicEpisode1::main();

}

