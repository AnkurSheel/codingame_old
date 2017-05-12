#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/War.h"
#include "gtest/gtest.h"

using namespace std;

class WarTest : public ::testing::Test
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

TEST_F(WarTest, 3Cards)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/3Cards_in.txt");
  War::main();
  EXPECT_STREQ("1 3", outputstream.str().data());
}

TEST_F(WarTest, 26Cards)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/26Cards_in.txt");
  War::main();
  EXPECT_STREQ("2 26", outputstream.str().data());
}

TEST_F(WarTest, 26CardsMediumLength)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/26CardsMediumLength_in.txt");
  War::main();
  EXPECT_STREQ("2 56", outputstream.str().data());
}

TEST_F(WarTest, Battle)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/Battle_in.txt");
  War::main();
  EXPECT_STREQ("2 1", outputstream.str().data());
}

TEST_F(WarTest, OneGameOneBattle)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/OneGameOneBattle_in.txt");
  War::main();
  EXPECT_STREQ("1 52", outputstream.str().data());
}

TEST_F(WarTest, TwoChainedBattles)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/TwoChainedBattles_in.txt");
  War::main();
  EXPECT_STREQ("2 1", outputstream.str().data());
}

TEST_F(WarTest, LongGame)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/LongGame_in.txt");
  War::main();
  EXPECT_STREQ("2 1262", outputstream.str().data());
}

TEST_F(WarTest, Pat1)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/Pat1_in.txt");
  War::main();
  EXPECT_STREQ("PAT", outputstream.str().data());
}

TEST_F(WarTest, Pat2)
{
  inputFile = ifstream("../tests/DataFiles/Medium/War/Pat2_in.txt");
  War::main();
  EXPECT_STREQ("PAT", outputstream.str().data());
}
