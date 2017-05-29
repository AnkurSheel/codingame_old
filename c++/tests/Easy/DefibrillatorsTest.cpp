
#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Easy/Defibrillators.h"
#include "gtest/gtest.h"

using namespace std;

class DefibrillatorsTest : public ::testing::Test
{
  virtual void SetUp() override
  {
    Common::RedirectCin(inputFile);
    Common::RedirectCout(outputstream);
    Common::RedirectCerr(errstream);
  }

  virtual void TearDown() override
  {
    Common::ResetCin();
    Common::ResetCout();
    Common::ResetCerr();
  }

protected:
  ifstream inputFile;
  stringstream outputstream;
  stringstream errstream;
};

TEST_F(DefibrillatorsTest, Example)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/Defibrillators/Example_in.txt");

  Defibrillators::main();

  EXPECT_STREQ("Maison de la Prevention Sante\n", outputstream.str().data());
}

TEST_F(DefibrillatorsTest, ExactPosition)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/Defibrillators/ExactPosition_in.txt");

  Defibrillators::main();

  EXPECT_STREQ("Cimetiere Saint-Etienne\n", outputstream.str().data());
}

TEST_F(DefibrillatorsTest, LargeDataset)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/Defibrillators/LargeDataset_in.txt");

  Defibrillators::main();

  EXPECT_STREQ("Caisse Primaire d'Assurance Maladie\n", outputstream.str().data());
}

TEST_F(DefibrillatorsTest, LargeDataset2)
{
  inputFile = ifstream("./c++/tests/DataFiles/Easy/Defibrillators/LargeDataset2_in.txt");

  Defibrillators::main();

  EXPECT_STREQ("Amphitheatre d'O\n", outputstream.str().data());
}
