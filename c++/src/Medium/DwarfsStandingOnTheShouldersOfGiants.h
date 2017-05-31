#ifndef DwarfsStandingOnTheShouldersOfGiants_H__
#define DwarfsStandingOnTheShouldersOfGiants_H__

#include <map>
namespace Common
{
  struct stGraphNode;
}
namespace DwarfsStandingOnTheShouldersOfGiants
{
  void main();
  int GetLongestChain(const Common::stGraphNode* const pVertex, std::map<int, int>& results);
}
#endif  // DwarfsStandingOnTheShouldersOfGiants_H__
