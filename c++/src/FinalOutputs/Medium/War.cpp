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


#ifndef _War_H__
#define _War_H__

#include <string>

namespace War
{
  void main();
  int GetCardValue(const std::string& card);
}

#endif  // !_War_H__

#include <list>

using namespace std;
using namespace War;

void War::main()
{
  list<string> player1Cards;
  list<string> player2Cards;
  int numberOfCards;

  cin >> numberOfCards;
  cin.ignore();
  for (int i = 0; i < numberOfCards; i++)
  {
    string cardp1;
    cin >> cardp1;
    cin.ignore();
    player1Cards.push_back(cardp1);
  }

  cin >> numberOfCards;
  cin.ignore();
  for (int i = 0; i < numberOfCards; i++)
  {
    string cardp2;
    cin >> cardp2;
    cin.ignore();
    player2Cards.push_back(cardp2);
  }

  int rounds = 0;
  string result = "PAT";
  bool war = false;
  list<string> player1CardsOnTable;
  list<string> player2CardsOnTable;

  while (true)
  {
    if (player1Cards.empty())
    {
      result = "2";
      break;
    }
    if (player2Cards.empty())
    {
      result = "1";
      break;
    }
    if (!war)
    {
      rounds++;
    }
    player1CardsOnTable.push_back(player1Cards.front());
    player2CardsOnTable.push_back(player2Cards.front());
    player1Cards.pop_front();
    player2Cards.pop_front();
    int player1Value = GetCardValue(player1CardsOnTable.back());
    int player2Value = GetCardValue(player2CardsOnTable.back());

    if (player1Value > player2Value)
    {
      player1Cards.splice(player1Cards.end(), player1CardsOnTable);
      player1Cards.splice(player1Cards.end(), player2CardsOnTable);
      war = false;
    }
    else if (player2Value > player1Value)
    {
      player2Cards.splice(player2Cards.end(), player1CardsOnTable);
      player2Cards.splice(player2Cards.end(), player2CardsOnTable);
      war = false;
    }
    else  // war
    {
      if (player1Cards.size() < 3 || player2Cards.size() < 3)
      {
        break;
      }
      for (int i = 0; i < 3; i++)
      {
        player1CardsOnTable.push_back(player1Cards.front());
        player2CardsOnTable.push_back(player2Cards.front());
        player1Cards.pop_front();
        player2Cards.pop_front();
      }
      war = true;
    }
  }
  cout << result;
  if (result != "PAT")
  {
    cout << " " << rounds;
  }
}

int War::GetCardValue(const string& card)
{
  string cardValue = card.substr(0, card.length() - 1);
  int value = atoi(cardValue.data());
  if (value == 0)
  {
    switch (cardValue[0])
    {
      case 'J':
        value = 11;
        break;
      case 'Q':
        value = 12;
        break;
      case 'K':
        value = 13;
        break;
      case 'A':
        value = 14;
        break;
    }
  }
  return value;
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  War::main();

}

