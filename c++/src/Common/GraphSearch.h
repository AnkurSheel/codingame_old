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
    void BreadthFirstSearch(stGraphNode* const start, stGraphNode* const end, const cGraph& graph,
                            std::list<stGraphNode*>& path);
  };
}
#endif  // GraphSearch_H__
