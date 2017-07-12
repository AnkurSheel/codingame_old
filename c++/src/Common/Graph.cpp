#include "Graph.h"
#include <algorithm>
#include "MemoryUtils.h"

using namespace std;
using namespace Common;

stGraphNode::stGraphNode(int data)
  : m_data(data)
{
}

cGraph::cGraph(bool isDirected)
  : m_isDirected(isDirected)
{
}

cGraph::~cGraph()
{
  for (Nodes::iterator iter = m_vertices.begin(); iter != m_vertices.end(); ++iter)
  {
    delete *iter;
  }
}

void cGraph::AddVertexIfRequired(int data)
{
  stGraphNode vertex(data);
  if (m_vertices.find(&vertex) == m_vertices.end())
  {
    stGraphNode* pVertex = new stGraphNode(data);
    m_vertices.insert(pVertex);
  }
}

stGraphNode* const cGraph::GetVertex(int data)
{
  stGraphNode vertex(data);
  auto iter = m_vertices.find(&vertex);
  return (*iter);
}

void cGraph::AddEdge(int vertex1, int vertex2)
{
  AddVertexIfRequired(vertex1);
  AddVertexIfRequired(vertex2);
  stGraphNode* const pVertex1 = GetVertex(vertex1);
  stGraphNode* const pVertex2 = GetVertex(vertex2);

  pVertex1->m_neighbours.insert(pVertex2);
  if (!m_isDirected)
  {
    pVertex2->m_neighbours.insert(pVertex1);
  }
}

void cGraph::RemoveEdge(int vertex1, int vertex2)
{
  auto vertex1Node = GetVertex(vertex1);
  auto vertex2Node = GetVertex(vertex2);
  vertex1Node->m_neighbours.erase(vertex2Node);
  vertex2Node->m_neighbours.erase(vertex1Node);
}

void cGraph::RemoveVertex(stGraphNode* pVertex)
{
  for (auto neighbour : pVertex->m_neighbours)
  {
    neighbour->m_neighbours.erase(pVertex);
    if (neighbour->m_neighbours.size() == 0)
    {
      RemoveVertex(neighbour);
    }
  }
  pVertex->m_neighbours.clear();
  m_vertices.erase(pVertex);
  SafeDelete(&pVertex);
}

int cGraph::GetVertexIndex(int data) const
{
  auto iter = std::find_if(m_vertices.begin(), m_vertices.end(),
                           [&data](const stGraphNode* p) { return data == p->GetData(); });

  return distance(m_vertices.begin(), iter);
}