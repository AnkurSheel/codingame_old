#include "DwarfsStandingOnTheShouldersOfGiants.h"
#include "../Common/Graph.h"
#include "../Common/Includes.h"

using namespace std;
using namespace Common;

//  *******************************************************************************************************************
void DwarfsStandingOnTheShouldersOfGiants::main()
{
  cGraph graph(true);
  int n;  // the number of relationships of influence
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
  {
    int x;  // a relationship of influence between two people (x influences y)
    int y;
    cin >> x >> y;
    graph.AddEdge(x, y);
    cin.ignore();
  }

  int maxCount = 0;
  map<int, int> results;
  for (auto iter = graph.GetVertices().begin(); iter != graph.GetVertices().end(); ++iter)
  {
    int count = GetLongestChain(*iter, results) + 1;
    if (maxCount < count)
    {
      maxCount = count;
    }
  }

  cout << maxCount << endl;
}

int DwarfsStandingOnTheShouldersOfGiants::GetLongestChain(const stGraphNode* const pVertex, map<int, int>& results)
{
  if (results.find(pVertex->GetData()) != results.end())
  {
    return results[pVertex->GetData()];
  }

  const Neighbours& neighbours = pVertex->m_neighbours;
  int count = 0;
  int maxCount = 0;
  for (auto iter = neighbours.begin(); iter != neighbours.end(); iter++)
  {
    count = GetLongestChain(*iter, results) + 1;
    if (maxCount < count)
    {
      maxCount = count;
    }
  }
  results[pVertex->GetData()] = maxCount;
  return maxCount;
}
