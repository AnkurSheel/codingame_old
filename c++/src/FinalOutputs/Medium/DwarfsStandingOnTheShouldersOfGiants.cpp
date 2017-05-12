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
#define DEBUGPRINTSTDIN(format, ...) DEBUGPRINT(format, ##__VA_ARGS__)
#endif  //  _INPUT
#define ll long long

typedef std::chrono::high_resolution_clock Clock;
using FpSeconds = std::chrono::duration<float, std::chrono::seconds::period>;
using FpMilliSeconds = std::chrono::duration<float, std::chrono::milliseconds::period>;

#endif  // _INCLUDES_H

#ifndef DwarfsStandingOnTheShouldersOfGiants_H__
#define DwarfsStandingOnTheShouldersOfGiants_H__

namespace Common
{
  struct stGraphNode;
}
namespace DwarfsStandingOnTheShouldersOfGiants
{
  void main();
  int GetLongestChain(const Common::stGraphNode* const pVertex);
}
#endif // DwarfsStandingOnTheShouldersOfGiants_H__



#ifndef Graph_H__
#define Graph_H__

#include <set>

namespace Common
{
  struct stGraphNode;
  typedef std::set<stGraphNode*> Neighbours;

  struct stGraphNode
  {
  public:
    stGraphNode(int data);
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
    cGraph(bool directed);
    ~cGraph();
    const Nodes& GetVertices() const { return m_vertices; }
    void AddEdge(int vertex1, int vertex2);

  private:
    stGraphNode* const GetVertex(int data);
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


using namespace std;
using namespace Common;

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
  for (auto iter = graph.GetVertices().begin(); iter != graph.GetVertices().end(); ++iter)
  {
    int count = GetLongestChain(*iter) + 1;
    if (maxCount < count)
    {
      maxCount = count;
    }
  }

  cout << maxCount << endl;
}

int DwarfsStandingOnTheShouldersOfGiants::GetLongestChain(const stGraphNode* const pVertex)
{
  const Neighbours& neighbours = pVertex->m_neighbours;
  int count = 0;
  int maxCount = 0;
  for (auto iter = neighbours.begin(); iter != neighbours.end(); iter++)
  {
    count = GetLongestChain(*iter) + 1;
    if (maxCount < count)
    {
      maxCount = count;
    }
  }
  return maxCount;
}



using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");

  DwarfsStandingOnTheShouldersOfGiants::main();
}

