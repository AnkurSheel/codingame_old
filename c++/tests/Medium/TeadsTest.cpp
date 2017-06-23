#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/Teads.h"
#include "gtest/gtest.h"

using namespace std;

class TeadsTest : public ::testing::Test
{
  virtual void SetUp() override
  {
    Common::RedirectCin(inputFile);

    Common::RedirectCout(outputstream);
  }

  virtual void TearDown() override
  {
    Common::ResetCin();
    Common::ResetCout();
  }

protected:
  ifstream inputFile;
  stringstream outputstream;
};

TEST_F(TeadsTest, Test1)
{
}
