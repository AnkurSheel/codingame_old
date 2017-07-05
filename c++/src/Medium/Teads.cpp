#include "Teads.h"
#include <stack>
#include "../Common/Custom2DArray.h"
#include "../Common/Graph.h"
#include "../Common/Includes.h"
#include "../Common/MemoryUtils.h"
#include "../Common/Tree.h"

using namespace Teads;
using namespace std;
using namespace Common;

int GetMaxDepth(stGraphNode* const pStart, const cGraph& graph, int depthToSearch)
{
  cCustom2DArray<bool> visited;
  visited.Init(graph.GetVertices().size(), 1);
  for (int i = 0; i < graph.GetVertices().size(); i++)
  {
    visited.SetElement(i, 0, false);
  }
  stack<cTreeNode<stGraphNode*>*> frontier;
  cTreeNode<stGraphNode*>* pRoot = new cTreeNode<stGraphNode*>(nullptr, nullptr);
  cTreeNode<stGraphNode*>* pCurrent = pRoot->AddChild(pStart);

  int maxDepth = 0;
  int vertexIndex = graph.GetVertexIndex(pStart->GetData());
  frontier.push(pCurrent);
  visited.SetElement(vertexIndex, 0, true);
  while (!frontier.empty())
  {
    pCurrent = frontier.top();
    frontier.pop();
    auto pGraphNode = pCurrent->GetData();
    vertexIndex = graph.GetVertexIndex(pGraphNode->GetData());
    visited.SetElement(vertexIndex, 0, true);

    int depth = pCurrent->GetDepth();
    if (depthToSearch > 0 && pGraphNode->m_neighbours.size() > 0 && (depth) >= depthToSearch)
    {
      return std::numeric_limits<int>::max();
    }

    if (maxDepth < depth)
    {
      maxDepth = depth;
    }

    for (auto iter = pGraphNode->m_neighbours.begin(); iter != pGraphNode->m_neighbours.end(); ++iter)
    {
      vertexIndex = graph.GetVertexIndex((*iter)->GetData());
      if (!(visited.GetElement(vertexIndex, 0)))
      {
        auto pNode = pCurrent->AddChild(*iter);
        frontier.push(pNode);
      }
    }
  }

  SafeDelete(&pRoot);
  return maxDepth;
}

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

  auto startTime = Clock::now();
  int minDepth = -1;
  for (auto iter = graph.GetVertices().begin(); iter != graph.GetVertices().end(); iter++)
  {
    int depth = GetMaxDepth((*iter), graph, minDepth);
    if (minDepth < 0 || depth < minDepth)
    {
      minDepth = depth;
    }
  }
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  // DEBUGPRINT("Time taken: %f\n", duration.count());
  cout << (minDepth - 1) << endl;
}
