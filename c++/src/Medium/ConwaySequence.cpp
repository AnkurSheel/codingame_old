#include "ConwaySequence.h"
#include <list>
#include "../Common/Includes.h"

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
