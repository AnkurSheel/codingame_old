#include <string>
#include "gtest/gtest.h"
int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  std::string filter;
//#if 0
//  filter += ":AsciiArt*";    // current feature
//#else
//  filter += "-*LargeDataset*";  // skip large datasets
//#endif

   //testing::GTEST_FLAG(filter) = filter;
  return RUN_ALL_TESTS();
}
