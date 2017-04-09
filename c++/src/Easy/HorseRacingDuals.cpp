#include "HorseRacingDuals.h"
#include "Common/Includes.h"

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
