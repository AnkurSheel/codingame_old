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
