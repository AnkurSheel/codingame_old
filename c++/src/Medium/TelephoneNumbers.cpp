#include "TelephoneNumbers.h"
#include "../Common/Tree.h"
#include "../Common/Includes.h"

using namespace std;
using namespace TelephoneNumbers;
using namespace Common;

void TelephoneNumbers::main()
{
  int N;
  cin >> N;
  cin.ignore();

  cTreeNode<int>* pRoot = new cTreeNode<int>(-1);
  cTreeNode<int>* pCurrentNode = nullptr;
  cTreeNode<int>* pTempNode = nullptr;
  int count = 0;

  for (int i = 0; i < N; i++)
  {
    string telephone;
    cin >> telephone;
    cin.ignore();

    pCurrentNode = pRoot;

    for (int i = 0; i < telephone.length(); i++)
    {
      int digit = telephone[i] - '0';
      pTempNode = pCurrentNode->GetChild(digit);
      if (pTempNode == nullptr)
      {
        count++;
        pTempNode = pCurrentNode->AddChild(digit);
      }
      pCurrentNode = pTempNode;
    }
  }

  cout << count << endl;
}
