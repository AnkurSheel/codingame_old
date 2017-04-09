#include "ChuckNorris.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int MAXBITS = 7;
string AsciiToBinary(int asciiCode)
{
  string binary(MAXBITS, '0');
  int i = MAXBITS - 1;
  while (asciiCode > 0)
  {
    binary[i--] = ((asciiCode % 2) == 0) ? '0' : '1';
    asciiCode /= 2;
  }
  return binary;
}

void ChuckNorris::main()
{
  string message = "";
  getline(cin, message);

  string binary = "";
  ostringstream chuckCode;
  for (int i = 0; i < message.length(); i++)
  {
    binary += AsciiToBinary(message[i]);
  }
  char currentBit = binary[0];
  int count = 0;
  int i = 0;
  while (i < binary.length())
  {
    while (i < binary.length() && binary[i] == currentBit)
    {
      i++;
      count++;
    }
    if (currentBit == '1')
    {
      chuckCode << '0';
      currentBit = '0';
    }
    else
    {
      chuckCode << "00";
      currentBit = '1';
    }
    chuckCode << " ";
    for (int k = 0; k < count; k++)
    {
      chuckCode << "0";
    }
    if (i < binary.length())
    {
      chuckCode << " ";
    }
    count = 0;
  }

  cout << chuckCode.str() << endl;
}
