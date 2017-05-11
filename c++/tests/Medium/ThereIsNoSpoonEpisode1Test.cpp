#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/ThereIsNoSpoonEpisode1.h"
#include "gtest/gtest.h"

using namespace std;

class ThereIsNoSpoonEpisode1Test : public ::testing::Test
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

TEST_F(ThereIsNoSpoonEpisode1Test, Example)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Example_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Example_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, Horizontal)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Horizontal_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Horizontal_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, Vertical)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Vertical_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Vertical_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, Square)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Square_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Square_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, T)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/T_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/T_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, Diagonal)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Diagonal_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Diagonal_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, Complex)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Complex_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Complex_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(ThereIsNoSpoonEpisode1Test, Shuriken)
{
  inputFile = ifstream("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Shuriken_in.txt");

  ThereIsNoSpoonEpisode1::main();

  resultFile.open("../tests/DataFiles/Medium/ThereIsNoSpoonEpisode1/Shuriken_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}
