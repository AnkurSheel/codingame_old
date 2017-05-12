#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/TelephoneNumbers.h"
#include "gtest/gtest.h"

using namespace std;

class TelephoneNumbersTest : public ::testing::Test
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

TEST_F(TelephoneNumbersTest, OneTelephoneNumber)
{
  inputFile = ifstream("../tests/DataFiles/Medium/TelephoneNumbers/OneTelephoneNumber_in.txt");
  TelephoneNumbers::main();
  EXPECT_STREQ("10\n", outputstream.str().data());
}

TEST_F(TelephoneNumbersTest, NumbersWithADifferentBase)
{
  inputFile = ifstream("../tests/DataFiles/Medium/TelephoneNumbers/NumbersWithADifferentBase_in.txt");
  TelephoneNumbers::main();
  EXPECT_STREQ("20\n", outputstream.str().data());
}

TEST_F(TelephoneNumbersTest, NumbersIncludedInAnother)
{
  inputFile = ifstream("../tests/DataFiles/Medium/TelephoneNumbers/NumbersIncludedInAnother_in.txt");
  TelephoneNumbers::main();
  EXPECT_STREQ("10\n", outputstream.str().data());
}

TEST_F(TelephoneNumbersTest, NumbersWithACommonPart)
{
  inputFile = ifstream("../tests/DataFiles/Medium/TelephoneNumbers/NumbersWithACommonPart_in.txt");
  TelephoneNumbers::main();
  EXPECT_STREQ("28\n", outputstream.str().data());
}

TEST_F(TelephoneNumbersTest, LargeDataset)
{
  inputFile = ifstream("../tests/DataFiles/Medium/TelephoneNumbers/LargeDataset_in.txt");
  TelephoneNumbers::main();
  EXPECT_STREQ("45512\n", outputstream.str().data());
}
