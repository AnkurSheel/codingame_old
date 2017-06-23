#include "Teads.h"
#include "../Common/Includes.h"

using namespace Teads;
using namespace std;

void Teads::main()
{
  int numberOfRelations;  // the number of adjacency relations
  cin >> numberOfRelations;
  cin.ignore();
  for (int i = 0; i < numberOfRelations; i++)
  {
    int id1;
    int id2;
    cin >> id1 >> id2;
    cin.ignore();
  }

  cout << "1" << endl;
}