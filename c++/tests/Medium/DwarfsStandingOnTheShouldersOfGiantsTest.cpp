#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/DwarfsStandingOnTheShouldersOfGiants.h"
#include "gtest/gtest.h"

using namespace std;

class DwarfsStandingOnTheShouldersOfGiantsTest : public ::testing::Test
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
  ifstream resultFile;
  stringstream outputstream;
};

TEST_F(DwarfsStandingOnTheShouldersOfGiantsTest, SimpleExample)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/DwarfsStandingOnTheShouldersOfGiants/SimpleExample_in.txt");

  DwarfsStandingOnTheShouldersOfGiants::main();

  EXPECT_STREQ("3\n", outputstream.str().data());
}

TEST_F(DwarfsStandingOnTheShouldersOfGiantsTest, CompleteExample)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/DwarfsStandingOnTheShouldersOfGiants/CompleteExample_in.txt");

  DwarfsStandingOnTheShouldersOfGiants::main();

  EXPECT_STREQ("4\n", outputstream.str().data());
}

TEST_F(DwarfsStandingOnTheShouldersOfGiantsTest, SeveralMentors)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/DwarfsStandingOnTheShouldersOfGiants/SeveralMentors_in.txt");

  DwarfsStandingOnTheShouldersOfGiants::main();

  EXPECT_STREQ("3\n", outputstream.str().data());
}
