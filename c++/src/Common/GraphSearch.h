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
