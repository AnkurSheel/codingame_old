#include "GraphSearch.h"
#include <list>
#include "Custom2DArray.h"
#include "Graph.h"
#include "Tree.h"

using namespace std;
using namespace Common;

//  *******************************************************************************************************************
void Common::cGraphSearch::BreadthFirstSearch(stGraphNode* const start, stGraphNode* const end, const cGraph& graph,
                                              std::list<stGraphNode*>& path)
{
  cCustom2DArray<bool> pVisited;
  pVisited.Init(graph.GetVertices().size(), 1, false);
  for (int i = 0; i < graph.GetVertices().size(); ++i)
  {
    pVisited.SetElement(i, 0, false);
  }

  list<stGraphNode*> frontier;
  cTreeNode<stGraphNode*>* pRoot = new cTreeNode<stGraphNode*>(nullptr, nullptr);
  cTreeNode<stGraphNode*>* pCurrent = pRoot;

  bool found = false;
  int vertexIndex = graph.GetVertexIndex(start->GetData());
  frontier.push_back(start);
  pVisited.SetElement(vertexIndex, 0, true);

  while (!found && !frontier.empty())
  {
    auto pGraphNode = frontier.front();
    frontier.pop_front();
    pCurrent = pCurrent->AddChild(pGraphNode);
    if (pCurrent->GetData() == end)
    {
      found = true;
      break;
    }
    for (auto iter = pGraphNode->m_neighbours.begin(); iter != pGraphNode->m_neighbours.end(); ++iter)
    {
      int vertexIndex = graph.GetVertexIndex((*iter)->GetData());
      if (!(pVisited.GetElement(vertexIndex, 0)))
      {
        frontier.push_back((*iter));
        pVisited.SetElement(vertexIndex, 0, true);
      }
    }
  }
  if (found)
  {
    while (pCurrent != pRoot)
    {
      path.push_front(pCurrent->GetData());
      pCurrent = pCurrent->GetParent();
    }
  }
}
