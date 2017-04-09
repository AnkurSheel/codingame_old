
#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Easy/HorseRacingDuals.h"
#include "gtest/gtest.h"

using namespace std;

class HorseRacingDualsTest : public ::testing::Test
{
  virtual void SetUp() override
  {
    RedirectIO::RedirectCin(inputFile);
    RedirectIO::RedirectCout(outputstream);
    RedirectIO::RedirectCerr(errstream);
  }

  virtual void TearDown() override
  {
    RedirectIO::ResetCin();
    RedirectIO::ResetCout();
    RedirectIO::ResetCerr();
  }

protected:
  ifstream inputFile;
  stringstream outputstream;
  stringstream errstream;
};

TEST_F(HorseRacingDualsTest, Simple)
{
  inputFile = ifstream("../tests/DataFiles/Easy/HorseRacingDuals/Simple_in.txt");

  HorseRacingDuals::main();

  EXPECT_STREQ("1\n", outputstream.str().data());
}

TEST_F(HorseRacingDualsTest, RandomOrder)
{
  inputFile = ifstream("../tests/DataFiles/Easy/HorseRacingDuals/RandomOrder_in.txt");

  HorseRacingDuals::main();

  EXPECT_STREQ("1\n", outputstream.str().data());
}

TEST_F(HorseRacingDualsTest, LargeDataset)
{
  inputFile = ifstream("../tests/DataFiles/Easy/HorseRacingDuals/LargeDataset_in.txt");

  HorseRacingDuals::main();

  EXPECT_STREQ("47\n", outputstream.str().data());
}