#include "AsciiArt.h"
#include "../Common/Includes.h"

using namespace std;
using namespace AsciiArt;

void AsciiArt::main()
{
  vector<string> rows;

  int widthOfLetter;
  cin >> widthOfLetter;
  cin.ignore();
  int heightOfLetter;
  cin >> heightOfLetter;
  cin.ignore();
  string text;
  getline(cin, text);

  for (int i = 0; i < heightOfLetter; i++)
  {
    string row;
    getline(cin, row);
    rows.push_back(row);
  }

  vector<string> output(heightOfLetter);
  for (int i = 0; i < text.length(); i++)
  {
    int startingIndex = 0;
    if (text[i] >= 'a' && text[i] <= 'z')
    {
      text[i] = toupper(text[i]);
    }
    int ascii = text[i];

    // if not a letter get index for ? which is after Z
    if (ascii < 'A' || ascii > 'Z')
    {
      ascii = 'Z' + 1;
    }

    ascii -= 'A';

    startingIndex = ascii * widthOfLetter;

    for (int j = 0; j < heightOfLetter; j++)
    {
      for (int k = 0; k < widthOfLetter; k++)
      {
        output[j] += rows[j][startingIndex + k];
      }
    }
  }

  for (int j = 0; j < heightOfLetter; j++)
  {
    cout << output[j] << endl;
  }
}
