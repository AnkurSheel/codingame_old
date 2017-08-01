#include "SkyNetRevolutionEpisode1.h"
#include "../Common/Custom2DArray.h"
#include "../Common/Graph.h"
#include "../Common/GraphSearch.h"
#include "../Common/Includes.h"
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
  list<stGraphNode*> bestPath;

  while (true)
  {
    int skyNetNodeIndex;  // The index of the node on which the Skynet agent is positioned this turn
    cin >> skyNetNodeIndex;
    cin.ignore();
    DEBUGPRINTSTDIN("%d\n", skyNetNodeIndex);

    bestPath.clear();
    size_t shortestPathCount = numeric_limits<size_t>::max();
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
    int vertex1 = (*iter)->GetData();
    ++iter;
    int vertex2 = (*iter)->GetData();
    graph.RemoveEdge(vertex1, vertex2);
    cout << vertex1 << " " << vertex2 << endl;
  }
}