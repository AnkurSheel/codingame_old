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
#if _DEBUG
    maxDuration = 50.0f;
#else
    maxDuration = 0.5f;
#endif  // _DEBUG
  }

  virtual void TearDown() override
  {
    Common::ResetCin();
    Common::ResetCout();
  }

protected:
  ifstream inputFile;
  stringstream outputstream;
  float maxDuration;
};

TEST_F(TeadsTest, Test1)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test1.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("2\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test2)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test2.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("2\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test3)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test3.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("3\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test4)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test4.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("5\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test5)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test5.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("5\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test6)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test6.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("7\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test7)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test7.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("15\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test8)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test8.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("9\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test9)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test9.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("15\n", outputstream.str().data());
}

TEST_F(TeadsTest, Test10)
{
  inputFile = ifstream("./c++/tests/DataFiles/Medium/Teads/Test10.txt");
  auto startTime = Clock::now();
  Teads::main();
  auto endTime = Clock::now();
  FpSeconds duration = endTime - startTime;
  EXPECT_LE(duration.count(), maxDuration);
  EXPECT_STREQ("5\n", outputstream.str().data());
}
