#ifndef _INCLUDES_H
#define _INCLUDES_H

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>

#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#define DEBUGPRINT(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#ifdef _INPUT
#define DEBUGPRINTSTDIN(format, ...)                                                                                   \
  fprintf(stderr, "IN\n");                                                                                             \
  fprintf(stderr, format, ##__VA_ARGS__);                                                                              \
  fprintf(stderr, "/IN\n")
#else
#define DEBUGPRINTSTDIN(format, ...)
#endif  //  _INPUT
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

#ifndef Teads_H__
#define Teads_H__

namespace Teads
{
  void main();
}
#endif // !Teads_H__


#ifndef Graph_H__
#define Graph_H__

#include <list>
#include <set>

namespace Common
{
  struct stGraphNode;
  typedef std::set<stGraphNode*> Neighbours;

  struct stGraphNode
  {
  public:
    explicit stGraphNode(int data);
    int GetData() const { return m_data; }
    bool operator<(const stGraphNode& ref) const { return (ref.m_data < m_data); }
    bool operator==(const stGraphNode& ref) const { return (ref.m_data == m_data); }

  public:
    Neighbours m_neighbours;

  private:
    int m_data;
  };

  struct myClassComp
  {
    bool operator()(const stGraphNode* lhs, const stGraphNode* rhs) const { return lhs->GetData() < rhs->GetData(); }
  };

  typedef std::set<stGraphNode*, myClassComp> Nodes;

  class cGraph
  {
  public:
    explicit cGraph(bool directed);
    ~cGraph();
    const Nodes& GetVertices() const { return m_vertices; }
    void AddEdge(int vertex1, int vertex2);
    void RemoveEdge(int vertex1, int vertex2);
    int GetVertexIndex(int data) const;
    stGraphNode* const GetVertex(int data);
    void RemoveVertex(stGraphNode* pVertex);

  private:
    void AddVertexIfRequired(int data);

  private:
    Nodes m_vertices;
    bool m_isDirected;
  };
}
#endif  // Graph_H__

#include <algorithm>
#ifndef _MemoryUtils_H__
#define _MemoryUtils_H__

template <typename Interface>
inline void SafeDeleteArray(Interface** ppArrayToDelete)
{
  if (*ppArrayToDelete != NULL)
  {
    delete[](*ppArrayToDelete);
    (*ppArrayToDelete) = NULL;
  }
}

template <typename Interface>
inline void SafeDelete(Interface** ppInterfaceToDelete)
{
  if (*ppInterfaceToDelete != NULL)
  {
    delete (*ppInterfaceToDelete);
    (*ppInterfaceToDelete) = NULL;
  }
}

#endif  // !_MemoryUtils_H__


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
  if (m_vertices.find(pVertex) == m_vertices.end())
  {
    return;
  }

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


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  Teads::main();

}

