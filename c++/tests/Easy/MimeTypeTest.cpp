#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Easy/MimeType.h"
#include "gtest/gtest.h"

using namespace std;

class MimeTypeTest : public ::testing::Test
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

TEST_F(MimeTypeTest, SimpleCase)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/MimeType/SimpleCase_in.txt");

  MimeType::main();

  resultFile.open("./c++/tests/DataFiles/Easy/MimeType/SimpleCase_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MimeTypeTest, UnknownTypes)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/MimeType/UnknownTypes_in.txt");

  MimeType::main();

  resultFile.open("./c++/tests/DataFiles/Easy/MimeType/UnknownTypes_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MimeTypeTest, CorrectDivision)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/MimeType/CorrectDivision_in.txt");

  MimeType::main();

  resultFile.open("./c++/tests/DataFiles/Easy/MimeType/CorrectDivision_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MimeTypeTest, CaseSensitivity)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/MimeType/CaseSensitivity_in.txt");

  MimeType::main();

  resultFile.open("./c++/tests/DataFiles/Easy/MimeType/CaseSensitivity_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MimeTypeTest, LargeDataset)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/MimeType/LargeDataset_in.txt");

  MimeType::main();

  resultFile.open("./c++/tests/DataFiles/Easy/MimeType/LargeDataset_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}
