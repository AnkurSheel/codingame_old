#include "Scrabble.h"
#include <algorithm>
#include <map>
#include <vector>
#include "../Common/Includes.h"

using namespace std;
using namespace Scrabble;

void Scrabble::main()
{
  vector<string> words;
  vector<string> possibleWords;
  int numberOfWords;
  cin >> numberOfWords;
  cin.ignore();
  for (int i = 0; i < numberOfWords; i++)
  {
    string word;
    getline(cin, word);
    if (word.length() <= 7)
    {
      words.push_back(word);
    }
  }
  string letters;
  getline(cin, letters);

  for (auto iter = words.begin(); iter != words.end(); iter++)
  {
    string sortedWord = *iter;
    sort(letters.begin(), letters.end());
    sort(sortedWord.begin(), sortedWord.end());
    if (includes(letters.begin(), letters.end(), sortedWord.begin(), sortedWord.end()))
    {
      possibleWords.push_back(*iter);
    }
  }

  int maxPoints = 0;
  string bestWord;
  for (auto iter = possibleWords.begin(); iter != possibleWords.end(); iter++)
  {
    int points = 0;
    for (int i = 0; i < (*iter).length(); i++)
    {
      points += GetPoints((*iter)[i]);
    }
    if (points > maxPoints)
    {
      maxPoints = points;
      bestWord = *iter;
    }
  }

  cout << bestWord << endl;
}

int Scrabble::GetPoints(char c)
{
  switch (c)
  {
    case 'e':
    case 'a':
    case 'i':
    case 'o':
    case 'n':
    case 'r':
    case 't':
    case 'l':
    case 's':
    case 'u':
      return 1;

    case 'd':
    case 'g':
      return 2;

    case 'b':
    case 'c':
    case 'm':
    case 'p':
      return 3;

    case 'f':
    case 'h':
    case 'v':
    case 'w':
    case 'y':
      return 4;

    case 'k':
      return 5;

    case 'j':
    case 'x':
      return 8;

    case 'q':
    case 'z':
      return 10;
  default: 
    return 0;
  };
}
