#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Easy/AsciiArt.h"
#include "gtest/gtest.h"

using namespace std;

class AsciiArtTest : public ::testing::Test
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

TEST_F(AsciiArtTest, OneLetter_E)
{
  inputFile = ifstream("../tests/DataFiles/Easy/AsciiArt/OneLetter_E_in.txt");

  AsciiArt::main();

  resultFile.open("../tests/DataFiles/Easy/AsciiArt/OneLetter_E_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(AsciiArtTest, ManhattanUpperCase)
{
  inputFile = ifstream("../tests/DataFiles/Easy/AsciiArt/ManhattanUpperCase_in.txt");

  AsciiArt::main();

  resultFile.open("../tests/DataFiles/Easy/AsciiArt/ManhattanUpperCase_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(AsciiArtTest, ManhattanMixedCase)
{
  inputFile = ifstream("../tests/DataFiles/Easy/AsciiArt/ManhattanMixedCase_in.txt");

  AsciiArt::main();

  resultFile.open("../tests/DataFiles/Easy/AsciiArt/ManhattanMixedCase_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(AsciiArtTest, ManhattanNonLetter)
{
  inputFile = ifstream("../tests/DataFiles/Easy/AsciiArt/ManhattanNonLetter_in.txt");

  AsciiArt::main();

  resultFile.open("../tests/DataFiles/Easy/AsciiArt/ManhattanNonLetter_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(AsciiArtTest, ManhattanAlternateRepresentation)
{
  inputFile = ifstream("../tests/DataFiles/Easy/AsciiArt/ManhattanAlternateRepresentation_in.txt");

  AsciiArt::main();

  resultFile.open("../tests/DataFiles/Easy/AsciiArt/ManhattanAlternateRepresentation_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}
