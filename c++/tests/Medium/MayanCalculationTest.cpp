#include <fstream>
#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Medium/MayanCalculation.h"
#include "gtest/gtest.h"

using namespace std;

class MayanCalculationTest : public ::testing::Test
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

TEST_F(MayanCalculationTest, SimpleAddition)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/SimpleAddition_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/SimpleAddition_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, AdditionWithCarry)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/AdditionWithCarry_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/AdditionWithCarry_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, Multiplication)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/Multiplication_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/Multiplication_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, SimpleSubtraction)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/SimpleSubtraction_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/SimpleSubtraction_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, Subtraction)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/Subtraction_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/Subtraction_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, SimpleDivision)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/SimpleDivision_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/SimpleDivision_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, Division)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/Division_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/Division_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, GreatMultiplication)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/GreatMultiplication_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/GreatMultiplication_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, Zero)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/Zero_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/Zero_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, MissingPower)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/MissingPower_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/MissingPower_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, Base20)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/Base20_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/Base20_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}

TEST_F(MayanCalculationTest, OtherSymbols)
{
  inputFile = ifstream("../tests/DataFiles/Medium/MayanCalculation/OtherSymbols_in.txt");

  MayanCalculation::main();

  resultFile.open("../tests/DataFiles/Medium/MayanCalculation/OtherSymbols_out.txt");
  stringstream expectedStream;
  expectedStream << resultFile.rdbuf();
  EXPECT_STREQ(expectedStream.str().data(), outputstream.str().data());
}
