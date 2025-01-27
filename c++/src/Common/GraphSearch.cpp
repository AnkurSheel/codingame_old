#include "GraphSearch.h"
#include <list>
#include "Custom2DArray.h"
#include "Graph.h"
#include "Tree.h"

using namespace std;
using namespace Common;

Common::cGraphSearch::cGraphSearch(cGraph* const pGraph)
  : m_pGraph(pGraph)
{
}

//  *******************************************************************************************************************
void Common::cGraphSearch::BreadthFirstSearch(stGraphNode* const start, stGraphNode* const end,
                                              std::list<stGraphNode*>& path)
{
  cCustom2DArray<bool> pVisited;
  pVisited.Init(m_pGraph->GetVertices().size(), 1, false);
  for (int i = 0; i < m_pGraph->GetVertices().size(); ++i)
  {
    pVisited.SetElement(i, 0, false);
  }

  list<cTreeNode<stGraphNode*>*> frontier;
  cTreeNode<stGraphNode*>* pRoot = new cTreeNode<stGraphNode*>(nullptr, nullptr);
  cTreeNode<stGraphNode*>* pCurrent = pRoot->AddChild(start);

  bool found = false;
  int vertexIndex = m_pGraph->GetVertexIndex(start->GetData());
  frontier.push_back(pCurrent);
  pVisited.SetElement(vertexIndex, 0, true);

  while (!found && !frontier.empty())
  {
    pCurrent = frontier.front();
    auto pGraphNode = pCurrent->GetData();
    frontier.pop_front();
    if (pCurrent->GetData() == end)
    {
      found = true;
      break;
    }
    for (auto iter = pGraphNode->m_neighbours.begin(); iter != pGraphNode->m_neighbours.end(); ++iter)
    {
      int vertexIndex = m_pGraph->GetVertexIndex((*iter)->GetData());
      if (!(pVisited.GetElement(vertexIndex, 0)))
      {
        auto pNode = pCurrent->AddChild(*iter);
        frontier.push_back(pNode);
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
