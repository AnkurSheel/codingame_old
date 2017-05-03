#include "Common/HexCubeCoordinate.h"
#include "gtest/gtest.h"

using namespace Common;

class HexCubeCoordinateTest : public ::testing::Test
{
  virtual void SetUp() override {}
  virtual void TearDown() override {}
protected:
};

TEST_F(HexCubeCoordinateTest, OddOffsetDistanceOrientation0)
{
  EXPECT_EQ(1, rOddOffsetDistance(2, 2, 3, 2));
  EXPECT_EQ(2, rOddOffsetDistance(2, 2, 4, 2));
}

TEST_F(HexCubeCoordinateTest, OddOffsetDistanceOrientation1)
{
  EXPECT_EQ(1, rOddOffsetDistance(2, 2, 2, 1));
  EXPECT_EQ(2, rOddOffsetDistance(2, 2, 3, 0));
}

TEST_F(HexCubeCoordinateTest, OddOffsetDistanceOrientation2)
{
  EXPECT_EQ(1, rOddOffsetDistance(2, 2, 1, 1));
  EXPECT_EQ(2, rOddOffsetDistance(2, 2, 1, 0));
}

TEST_F(HexCubeCoordinateTest, OddOffsetDistanceOrientation3)
{
  EXPECT_EQ(1, rOddOffsetDistance(2, 2, 1, 2));
  EXPECT_EQ(2, rOddOffsetDistance(2, 2, 0, 2));
}

TEST_F(HexCubeCoordinateTest, OddOffsetDistanceOrientation4)
{
  EXPECT_EQ(1, rOddOffsetDistance(2, 2, 1, 3));
  EXPECT_EQ(2, rOddOffsetDistance(2, 2, 1, 4));
}

TEST_F(HexCubeCoordinateTest, OddOffsetDistanceOrientation5)
{
  EXPECT_EQ(1, rOddOffsetDistance(2, 2, 2, 3));
  EXPECT_EQ(2, rOddOffsetDistance(2, 2, 3, 4));
}

TEST_F(HexCubeCoordinateTest, RoundTripConversion)
{
  cPoint<int> pointA(1, 3);
  EXPECT_EQ(pointA, rOddOffsetFromCube(rOddOffsetToCube(pointA.GetX(), pointA.GetY())));
}

TEST_F(HexCubeCoordinateTest, HexOddNeighborOrientation0)
{
  cPoint<int> pointB(3, 2);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 0;
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 1));
  pointB = cPoint<int>(4, 2);
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 2));
}

TEST_F(HexCubeCoordinateTest, HexOddNeighborOrientation1)
{
  cPoint<int> pointB(2, 1);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 1;
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 1));
  pointB = cPoint<int>(3, 0);
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 2));
}

TEST_F(HexCubeCoordinateTest, HexOddNeighborOrientation2)
{
  cPoint<int> pointB(1, 1);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 2;
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 1));
  pointB = cPoint<int>(1, 0);
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 2));
}

TEST_F(HexCubeCoordinateTest, HexOddNeighborOrientation3)
{
  cPoint<int> pointB(1, 2);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 3;
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 1));
  pointB = cPoint<int>(0, 2);
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 2));
}

TEST_F(HexCubeCoordinateTest, HexOddNeighborOrientation4)
{
  cPoint<int> pointB(1, 3);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 4;
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 1));
  pointB = cPoint<int>(1, 4);
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 2));
}

TEST_F(HexCubeCoordinateTest, HexOddNeighborOrientation5)
{
  cPoint<int> pointB(2, 3);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 5;
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 1));
  pointB = cPoint<int>(3, 4);
  EXPECT_EQ(pointB, OddOffsetNeighbor(xPos, yPos, direction, 2));
}
