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


#ifndef _ConwaySequence_H__
#define _ConwaySequence_H__

namespace ConwaySequence
{
  void main();
}

#endif  // !_ConwaySequence_H__

#include <list>

using namespace std;
using namespace ConwaySequence;

void ConwaySequence::main()
{
  int startingNumber;
  cin >> startingNumber;
  cin.ignore();
  int numberOfLines;
  cin >> numberOfLines;
  cin.ignore();

  list<int> sequence;
  sequence.push_back(startingNumber);
  for (int i = 1; i < numberOfLines; i++)
  {
    int count = 0;
    int previousNumber = *(sequence.begin());
    int number = 0;
    int size = sequence.size();
    int currentIndex = 0;

    while (currentIndex < size)
    {
      number = *(sequence.begin());
      if (number == previousNumber)
      {
        count++;
      }
      else
      {
        sequence.push_back(count);
        sequence.push_back(previousNumber);
        count = 1;
        previousNumber = number;
      }
      currentIndex++;
      sequence.pop_front();
    }
    sequence.push_back(count);
    sequence.push_back(number);
  }

  int i = 0;
  for (auto iter = sequence.begin(); iter != sequence.end(); iter++)
  {
    cout << *iter;
    if (i == sequence.size() - 1)
    {
      cout << endl;
    }
    else
    {
      cout << " ";
    }
    i++;
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  ConwaySequence::main();

}

