#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Easy/ChuckNorris.h"
#include "gtest/gtest.h"

using namespace std;

class ChuckNorrisTest : public ::testing::Test
{
  virtual void SetUp() override
  {
    Common::RedirectCin(inputstream);

    Common::RedirectCout(outputstream);
  }

  virtual void TearDown() override
  {
    Common::ResetCin();
    Common::ResetCout();
  }

protected:
  stringstream inputstream;
  stringstream outputstream;
};

TEST_F(ChuckNorrisTest, CharacterC)
{
  inputstream << "C\n";

  ChuckNorris::main();

  EXPECT_STREQ("0 0 00 0000 0 00\n", outputstream.str().data());
}

TEST_F(ChuckNorrisTest, MessageCC)
{
  inputstream << "CC\n";

  ChuckNorris::main();

  EXPECT_STREQ("0 0 00 0000 0 000 00 0000 0 00\n", outputstream.str().data());
}

TEST_F(ChuckNorrisTest, CharacterPercentage)
{
  inputstream << "%\n";

  ChuckNorris::main();

  EXPECT_STREQ("00 0 0 0 00 00 0 0 00 0 0 0\n", outputstream.str().data());
}

TEST_F(ChuckNorrisTest, LongMessage)
{
  inputstream << "Chuck Norris' keyboard has 2 keys: 0 and white space.\n";

  ChuckNorris::main();

  EXPECT_STREQ(
      "0 0 00 0000 0 0000 00 0 0 0 00 000 0 000 00 0 0 0 00 0 0 000 00 000 0 0000 00 0 0 0 00 0 0 00 00 0 0 0 00 00000 "
      "0 0 00 00 0 000 00 0 0 00 00 0 0 0000000 00 00 0 0 00 0 0 000 00 00 0 0 00 0 0 00 00 0 0 0 00 00 0 0000 00 00 0 "
      "00 00 0 0 0 00 00 0 000 00 0 0 0 00 00000 0 00 00 0 0 0 00 0 0 0000 00 00 0 0 00 0 0 00000 00 00 0 000 00 000 0 "
      "0 00 0 0 00 00 0 0 000000 00 0000 0 0000 00 00 0 0 00 0 0 00 00 00 0 0 00 000 0 0 00 00000 0 00 00 0 0 0 00 000 "
      "0 00 00 0000 0 0000 00 00 0 00 00 0 0 0 00 000000 0 00 00 00 0 0 00 00 0 0 00 00000 0 00 00 0 0 0 00 0 0 0000 "
      "00 00 0 0 00 0 0 00000 00 00 0 0000 00 00 0 00 00 0 0 000 00 0 0 0 00 00 0 0 00 000000 0 00 00 00000 0 0 00 "
      "00000 0 00 00 0000 0 000 00 0 0 000 00 0 0 00 00 00 0 0 00 000 0 0 00 00000 0 000 00 0 0 00000 00 0 0 0 00 000 "
      "0 00 00 0 0 0 00 00 0 0000 00 0 0 0 00 00 0 00 00 00 0 0 00 0 0 0 00 0 0 0 00 00000 0 000 00 00 0 00000 00 0000 "
      "0 00 00 0000 0 000 00 000 0 0000 00 00 0 0 00 0 0 0 00 0 0 0 00 0 0 000 00 0\n",
      outputstream.str().data());
}
