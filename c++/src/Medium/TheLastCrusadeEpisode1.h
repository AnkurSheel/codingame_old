#ifndef TheLastCrusadeEpisode1_H__
#define TheLastCrusadeEpisode1_H__
#include "../Common/Custom2DArray.h"

namespace TheLastCrusadeEpisode1
{
  void GetNextPos(int gridType, const std::string& entrancePoint,
                  int& newColumn, int& newRow);
  void main();
}

#endif  // !TheLastCrusadeEpisode1_H__
