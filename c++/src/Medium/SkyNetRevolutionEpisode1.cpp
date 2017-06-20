#include "SkyNetRevolutionEpisode1.h"
#include "../Common/Custom2DArray.h"
#include "../Common/Graph.h"
#include "../Common/Includes.h"
using namespace std;
using namespace Common;

void SkyNetRevolutionEpisode1::main()
{
  int numberOfNodes;
  int numberOfLinks;
  int numberOfExits;
  cin >> numberOfNodes >> numberOfLinks >> numberOfExits;
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
    graph.AddEdge(node1, node2);
  }
  for (int i = 0; i < numberOfExits; i++)
  {
    int exitNodeIndex;
    cin >> exitNodeIndex;
    gatewayNodeIndices.SetElement(i, 0, exitNodeIndex);
    cin.ignore();
  }

  // game loop
  while (1)
  {
    int skyNetNodeIndex;  // The index of the node on which the Skynet agent is positioned this turn
    cin >> skyNetNodeIndex;
    cin.ignore();

    cout << "0 1" << endl;
  }
}