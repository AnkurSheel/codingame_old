#include "Teads.h"
#include "../Common/Graph.h"
#include "../Common/Includes.h"

using namespace Teads;
using namespace std;
using namespace Common;

void Teads::main()
{
  cGraph graph(false);
  int numberOfRelations;  // the number of adjacency relations
  cin >> numberOfRelations;
  cin.ignore();

  for (int i = 0; i < numberOfRelations; i++)
  {
    int id1;
    int id2;
    cin >> id1 >> id2;
    cin.ignore();
    graph.AddEdge(id1, id2);
  }

  // use leaf removal algorithm to get center of tree
  int depth = 0;
  list<stGraphNode*> deletedNodes;
  while (graph.GetVertices().size() > 0)
  {
    deletedNodes.clear();
    for (auto pGraphNode : graph.GetVertices())
    {
      if (pGraphNode->m_neighbours.size() <= 1)
      {
        deletedNodes.push_back(pGraphNode);
      }
    }

    if (deletedNodes.size() > 0)
    {
      depth++;
      for (auto deletedNode : deletedNodes)
      {
        graph.RemoveVertex(deletedNode);
      }
    }
  }
  cout << depth << endl;
}
