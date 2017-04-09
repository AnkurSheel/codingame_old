#include "Common/Includes.h"
#include "Common/RedirectIO.h"
#include "Easy/Temperatures.h"
#include "gtest/gtest.h"

using namespace std;

class TemperaturesTest : public ::testing::Test
{
  virtual void SetUp() override
  {
    RedirectIO::RedirectCin(inputstream);

    RedirectIO::RedirectCout(outputstream);
  }

  virtual void TearDown() override
  {
    RedirectIO::ResetCin();
    RedirectIO::ResetCout();
  }

protected:
  stringstream inputstream;
  stringstream outputstream;
};

TEST_F(TemperaturesTest, Simple)
{
  inputstream << 5 << "\n";
  inputstream << 1 << " " << -2 << " " << -8 << " " << 4 << " " << 5;

  Temperatures::main();

  EXPECT_STREQ("1\n", outputstream.str().data());
}

TEST_F(TemperaturesTest, OnlyNegativeNumbers)
{
  inputstream << 3 << "\n";
  inputstream << -12 << " " << -5 << " " << -137;

  Temperatures::main();

  EXPECT_STREQ("-5\n", outputstream.str().data());
}

TEST_F(TemperaturesTest, ChooseTheRightTemperature)
{
  inputstream << 6 << "\n";
  inputstream << 42 << " " << -5 << " " << 12 << " " << 21 << " " << 5 << " " << 24;

  Temperatures::main();

  EXPECT_STREQ("5\n", outputstream.str().data());
}

TEST_F(TemperaturesTest, ChooseTheRightTemperature2)
{
  inputstream << 6 << "\n";
  inputstream << 42 << " " << 5 << " " << 12 << " " << 21 << " " << -5 << " " << 24;

  Temperatures::main();

  EXPECT_STREQ("5\n", outputstream.str().data());
}

TEST_F(TemperaturesTest, Complex)
{
  inputstream << 10 << "\n";
  inputstream << -5 << " " << -4 << " " << -2 << " " << 12 << " " << -40 << " " << 4 << " " << 2 << " " << 18 << " "
              << 11 << " " << 5;

  Temperatures::main();

  EXPECT_STREQ("2\n", outputstream.str().data());
}

TEST_F(TemperaturesTest, None)
{
  inputstream << 0 << "\n";

  Temperatures::main();

  EXPECT_STREQ("0\n", outputstream.str().data());
}