#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/StockExchangeLosses.h"
#include "gtest/gtest.h"

using namespace std;

class StockExchangeLossesTest : public ::testing::Test
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

TEST_F(StockExchangeLossesTest, Example1)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/StockExchangeLosses/Example1_in.txt");

  StockExchangeLosses::main();

  EXPECT_STREQ("-3\n", outputstream.str().data());
}

TEST_F(StockExchangeLossesTest, Example2)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/StockExchangeLosses/Example2_in.txt");

  StockExchangeLosses::main();

  EXPECT_STREQ("-4\n", outputstream.str().data());
}

TEST_F(StockExchangeLossesTest, Example3)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/StockExchangeLosses/Example3_in.txt");

  StockExchangeLosses::main();

  EXPECT_STREQ("0\n", outputstream.str().data());
}

TEST_F(StockExchangeLossesTest, Example4)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/StockExchangeLosses/Example4_in.txt");

  StockExchangeLosses::main();

  EXPECT_STREQ("0\n", outputstream.str().data());
}

TEST_F(StockExchangeLossesTest, Example5)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/StockExchangeLosses/Example5_in.txt");

  StockExchangeLosses::main();

  EXPECT_STREQ("-1073730311\n", outputstream.str().data());
}

TEST_F(StockExchangeLossesTest, Example6)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/StockExchangeLosses/Example6_in.txt");

  StockExchangeLosses::main();

  EXPECT_STREQ("-3\n", outputstream.str().data());
}
