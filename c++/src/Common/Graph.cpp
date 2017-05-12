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