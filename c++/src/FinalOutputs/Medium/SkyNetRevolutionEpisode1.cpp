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

#ifndef SkyNetRevolutionEpisode1_H__
#define SkyNetRevolutionEpisode1_H__

namespace SkyNetRevolutionEpisode1
{
  void main();
}
#endif  // !SkyNetRevolutionEpisode1_H__

#ifndef Custom2DArray_H__
#define Custom2DArray_H__

#include <cassert>
#include <cstring>
#include <iomanip>

namespace Common
{
  template <class Type>
  class cCustom2DArray
  {
  public:
    cCustom2DArray();
    ~cCustom2DArray();

    void Init(int rows, int columns, bool reset = true);
    const Type& GetElement(int row, int column) const;
    Type& GetElement(int row, int column);
    void SetElement(int row, int column, const Type& value);

  private:
    void Reset();
    int GetIndex(int row, int column) const { return row * m_numberOfColumns + column; }
    int GetSize() const { return m_numberOfRows * m_numberOfColumns; }

  private:
    Type* m_array;
    int m_numberOfRows;
    int m_numberOfColumns;
  };

  template <class Type>
  cCustom2DArray<Type>::cCustom2DArray()
    : m_array(nullptr)
    , m_numberOfRows(0)
    , m_numberOfColumns(0)
  {
  }

  template <class Type>
  cCustom2DArray<Type>::~cCustom2DArray()
  {
    delete[] m_array;
    m_array = nullptr;
  }

  template <class Type>
  void cCustom2DArray<Type>::Init(int rows, int columns, bool reset)
  {
    if (rows != m_numberOfRows || columns != m_numberOfColumns || !reset)
    {
      if (m_array != nullptr)
      {
        delete[] m_array;
        m_array = nullptr;
      }

      m_numberOfRows = rows;
      m_numberOfColumns = columns;

      m_array = new Type[GetSize()];
    }
    if (reset)
    {
      Reset();
    }
  }

  template <class Type>
  const Type& cCustom2DArray<Type>::GetElement(int row, int column) const 
  {
    assert(row >= 0 && row < m_numberOfRows && column >= 0 && column < m_numberOfColumns);
    return m_array[GetIndex(row, column)];
  }

  template <class Type>
  Type& cCustom2DArray<Type>::GetElement(int row, int column)
  {
    assert(row >= 0 && row < m_numberOfRows && column >= 0 && column < m_numberOfColumns);
    return m_array[GetIndex(row, column)];
  }

  template <class Type>
  void cCustom2DArray<Type>::SetElement(int row, int column, const Type& value)
  {
    assert(row >= 0 && row < m_numberOfRows && column >= 0 && column < m_numberOfColumns);
    m_array[GetIndex(row, column)] = value;
  }

  template <class Type>
  void cCustom2DArray<Type>::Reset()
  {
    if (m_array != nullptr)
    {
      memset(m_array, -1, GetSize() * sizeof(Type));
    }
  }
}
#endif  // Custom2DArray_H__

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
    void RemoveEdge(int vertex1, int vertex2);
    int GetVertexIndex(int data) const;
    stGraphNode* const GetVertex(int data);

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

int cGraph::GetVertexIndex(int data) const
{
  auto iter = std::find_if(m_vertices.begin(), m_vertices.end(),
                           [&data](const stGraphNode* p) { return data == p->GetData(); });

  return distance(m_vertices.begin(), iter);
}

#ifndef GraphSearch_H__
#define GraphSearch_H__

#include <list>

namespace Common
{
  struct stGraphNode;
  class cGraph;

  class cGraphSearch
  {
  public:
    cGraphSearch(cGraph* const pGraph);
    void BreadthFirstSearch(stGraphNode* const start, stGraphNode* const end, std::list<stGraphNode*>& path);

  private:
    cGraph* const m_pGraph;
  };
}
#endif  // GraphSearch_H__

#include <list>
#ifndef _TREE_H
#define _TREE_H
#include <vector>

namespace Common
{
  template <class T>
  class cTreeNode
  {
  public:
    cTreeNode(cTreeNode* const pParent, const T& data);
    ~cTreeNode();
    T GetData() const { return m_data; }
    cTreeNode* GetParent() const { return m_pParent; }
    cTreeNode* const GetChild(const T& value) const;
    cTreeNode* const AddChild(const T& value);

  private:
    T m_data;
    cTreeNode* m_pParent;
    std::vector<cTreeNode*> m_children;
  };

  template <class T>
  cTreeNode<T>::cTreeNode(cTreeNode* const pParent, const T& data)
    : m_data(data)
    , m_pParent(pParent)
  {
  }

  template <class T>
  cTreeNode<T>::~cTreeNode()
  {
    for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
    {
      SafeDelete(*iter);
    }
    m_pParent = nullptr;
  }

  template <class T>
  cTreeNode<T>* const cTreeNode<T>::GetChild(const T& value) const
  {
    for (auto iter = m_children.begin(); iter != m_children.end(); iter++)
    {
      if ((*iter)->m_data == value)
      {
        return *iter;
      }
    }
    return nullptr;
  }

  template <class T>
  cTreeNode<T>* const cTreeNode<T>::AddChild(const T& value)
  {
    cTreeNode* pNode = new cTreeNode(this, value);
    m_children.push_back(pNode);
    return pNode;
  }
}
#endif  // !_TREE_H


using namespace std;
using namespace Common;

Common::cGraphSearch::cGraphSearch(cGraph* const pGraph)
  : m_pGraph(pGraph)
{
}

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

using namespace std;
using namespace Common;

void SkyNetRevolutionEpisode1::main()
{
  int numberOfNodes;
  int numberOfLinks;
  int numberOfExits;
  cin >> numberOfNodes >> numberOfLinks >> numberOfExits;
  DEBUGPRINTSTDIN("%d %d %d\n", numberOfNodes, numberOfLinks, numberOfExits);
  cin.ignore();

  cGraph graph(false);
  cCustom2DArray<int> gatewayNodeIndices;
  gatewayNodeIndices.Init(numberOfExits, 1);

  for (int i = 0; i < numberOfLinks; i++)
  {
    int node1;
    int node2;
    cin >> node1 >> node2;
    cin.ignore();
    DEBUGPRINTSTDIN("%d %d\n", node1, node2);
    graph.AddEdge(node1, node2);
  }
  for (int i = 0; i < numberOfExits; i++)
  {
    int exitNodeIndex;
    cin >> exitNodeIndex;
    cin.ignore();
    DEBUGPRINTSTDIN("%d\n", exitNodeIndex);
    gatewayNodeIndices.SetElement(i, 0, exitNodeIndex);
  }
  
  cGraphSearch search(&graph);
  std::list<stGraphNode*> bestPath;
  int vertex1 = 0;
  int vertex2 = 0;
  
  while (1)
  {
    int skyNetNodeIndex;  // The index of the node on which the Skynet agent is positioned this turn
    cin >> skyNetNodeIndex;
    cin.ignore();
    DEBUGPRINTSTDIN("%d\n", skyNetNodeIndex);

    bestPath.clear();
    int shortestPathCount = numeric_limits<int>::max();
    for (int i = 0; i < numberOfExits; i++)
    {
      std::list<stGraphNode*> path;
      search.BreadthFirstSearch(graph.GetVertex(skyNetNodeIndex), graph.GetVertex(gatewayNodeIndices.GetElement(i, 0)),
                                path);
      
      if (path.size() > 0 && path.size() < shortestPathCount)
      {
        bestPath = path;
        shortestPathCount = path.size();
      }
    }

    auto iter = bestPath.begin();
    vertex1 = (*iter)->GetData();
    ++iter;
    vertex2 = (*iter)->GetData();
    graph.RemoveEdge(vertex1, vertex2);
    cout << vertex1 << " " << vertex2 << endl;
  }
}


using namespace std;

int main(int argc, char** argv)
{

  static_assert(std::chrono::treat_as_floating_point<FpMilliSeconds::rep>::value, "Rep required to be floating point");
  SkyNetRevolutionEpisode1::main();
}

