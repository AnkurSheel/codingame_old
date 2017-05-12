#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/Scrabble.h"
#include "gtest/gtest.h"

using namespace std;

class ScrabbleTest : public ::testing::Test
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

TEST_F(ScrabbleTest, OnlyOneWord)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/OnlyOneWord_in.txt");

  Scrabble::main();

  EXPECT_STREQ("which\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, TwoWordsWithSameValue)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/TwoWordsWithSameValue_in.txt");

  Scrabble::main();

  EXPECT_STREQ("potsie\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, TwoWordsWithDifferentValue)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/TwoWordsWithDifferentValue_in.txt");

  Scrabble::main();

  EXPECT_STREQ("powers\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, ManyPossibilities)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/ManyPossibilities_in.txt");

  Scrabble::main();

  EXPECT_STREQ("waster\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, ValueBetterThanSize)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/ValueBetterThanSize_in.txt");

  Scrabble::main();

  EXPECT_STREQ("tween\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, ValidWord)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/ValidWord_in.txt");

  Scrabble::main();

  EXPECT_STREQ("aeiou\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, LargeDataset1)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/LargeDataset1_in.txt");

  Scrabble::main();

  EXPECT_STREQ("satire\n", outputstream.str().data());
}

TEST_F(ScrabbleTest, LargeDataset2)
{
  inputFile = ifstream("../tests/DataFiles/Medium/Scrabble/LargeDataset2_in.txt");

  Scrabble::main();

  EXPECT_STREQ("pastern\n", outputstream.str().data());
}
