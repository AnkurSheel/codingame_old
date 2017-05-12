#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/ConwaySequence.h"
#include "gtest/gtest.h"

using namespace std;

class ConwaySequenceTest : public ::testing::Test
{
  virtual void SetUp() override
  {
    Common::RedirectCin(inputStream);

    Common::RedirectCout(outputstream);
  }

  virtual void TearDown() override
  {
    Common::ResetCin();
    Common::ResetCout();
  }

protected:
  stringstream inputStream;
  stringstream outputstream;
};

TEST_F(ConwaySequenceTest, Example1)
{
  inputStream << "1 \n 11\n";
  ConwaySequence::main();
  EXPECT_STREQ("1 1 1 3 1 2 2 1 1 3 3 1 1 2 1 3 2 1 1 3 2 1 2 2 2 1\n", outputstream.str().data());
}

TEST_F(ConwaySequenceTest, Example2)
{
  inputStream << "2 \n 1\n";
  ConwaySequence::main();
  EXPECT_STREQ("2\n", outputstream.str().data());
}

TEST_F(ConwaySequenceTest, Example3)
{
  inputStream << "5 \n 10\n";
  ConwaySequence::main();
  EXPECT_STREQ("3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 5\n", outputstream.str().data());
}

TEST_F(ConwaySequenceTest, Example4)
{
  inputStream << "25 \n 10\n";
  ConwaySequence::main();
  EXPECT_STREQ("3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 25\n", outputstream.str().data());
}

TEST_F(ConwaySequenceTest, Example5)
{
  inputStream << "1 \n 25\n";
  ConwaySequence::main();
  EXPECT_STREQ("1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 1 2 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 3 2 1 1 3 3 1 1 2 1 3 2 1 1 2 3 1 2 3 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 3 2 1 1 3 2 1 2 2 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 2 3 1 2 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 2 3 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 1 2 3 1 1 2 1 1 1 3 1 2 1 1 1 3 1 2 2 1 2 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 2 3 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 1 1 1 2 1 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 1 1 1 3 1 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 2 1 2 2 2 1 1 2 1 1 2 3 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 1 2 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 2 2 1 3 2 1 1 3 2 1 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 2 2 1 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 3 2 2 1 1 3 3 2 1 1 3 2 2 1 1 2 2 1 1 2 1 3 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 3 1 1 3 1 1 2 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 2 1 2 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 3 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 1 2 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 3 2 1 1 3 2 1 2 2 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 3 2 2 1 1 3 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 2 2 1 3 2 1 1 3 2 1 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 1 1 1 2 1 3 2 1 1 2 2 1 1 2 1 3 2 2 3 1 1 2 1 1 1 3 1 2 2 1 1 3 3 2 2 1 1 3 1 1 1 2 2 1 1 3 1 2 2 1\n", outputstream.str().data());
}

TEST_F(ConwaySequenceTest, Example6)
{
  inputStream << "33 \n 25\n";
  ConwaySequence::main();
  EXPECT_STREQ("3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 3 1 1 3 1 1 2 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 2 1 2 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 3 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 1 3 2 2 1 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 1 1 1 3 1 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 2 1 2 2 2 1 1 2 1 1 2 3 2 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 1 1 1 2 1 3 2 1 3 2 1 1 2 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 2 3 2 2 2 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 2 3 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 1 1 1 2 1 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 1 1 1 3 1 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 2 1 2 2 2 1 1 2 1 1 2 3 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 1 2 3 1 1 2 1 1 1 3 1 1 2 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 2 2 1 3 2 1 1 3 2 1 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 3 1 1 2 1 3 2 1 2 3 2 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 2 2 1 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 3 2 2 1 1 3 3 2 1 1 3 2 2 1 1 2 2 1 1 2 1 3 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 3 1 1 2 1 3 2 1 1 3 2 1 2 2 2 1 2 2 1 1 1 3 1 2 2 1 1 3 1 2 1 1 1 3 2 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 1 1 1 2 1 3 3 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 3 1 1 2 1 3 2 1 1 3 2 2 1 3 2 1 1 2 3 1 1 3 2 1 3 2 2 1 1 2 1 1 1 3 1 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 2 1 2 2 2 1 1 2 1 1 2 3 2 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 1 3 1 1 1 2 3 1 1 3 3 2 1 1 1 2 1 3 1 2 2 1 1 2 3 1 1 3 1 1 1 2 3 1 1 2 1 1 1 3 3 1 1 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 3 2 2 1 1 1 3 1 2 2 1 1 2 1 3 1 1 1 2 1 3 1 2 2 1 1 2 1 3 2 1 1 3 2 1 3 2 2 1 1 2 3 1 1 3 1 1 2 2 2 1 2 3 2 1 1 2 1 1 1 3 1 2 2 1 1 3 2 2 1 1 1 3 1 2 2 1 1 2 1 3 2 1 1 3 1 1 1 2 3 1 1 3 2 2 3 1 1 2 1 1 1 3 2 1 3 2 2 1 2 3 1 2 2 1 1 3 2 2 2 1 2 2 2 1 1 2 1 1 2 3 2 2 2 1 1 33\n", outputstream.str().data());
}
