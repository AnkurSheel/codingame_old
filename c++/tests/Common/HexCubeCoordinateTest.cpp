#include "Common/HexCubeCoordinate.h"
#include "gtest/gtest.h"

using namespace HexCubeCoordinate;

class HexCubeCoordinateTest : public ::testing::Test
{
  virtual void SetUp() override {}
  virtual void TearDown() override {}
protected:
};

TEST_F(HexCubeCoordinateTest, EvenLineOrientation0)
{
  cPoint<double> pointA(2, 2);
  cPoint<double> pointB(3, 2);
  EXPECT_EQ(1, rOddOffsetDistance(pointA, pointB));

  pointB = cPoint<double>(4, 2);
  EXPECT_EQ(2, rOddOffsetDistance(pointA, pointB));
}

TEST_F(HexCubeCoordinateTest, EvenLineOrientation1)
{
  cPoint<double> pointA(2, 2);
  cPoint<double> pointB(2, 1);
  EXPECT_EQ(1, rOddOffsetDistance(pointA, pointB));

  pointB = cPoint<double>(3, 0);
  EXPECT_EQ(2, rOddOffsetDistance(pointA, pointB));
}

TEST_F(HexCubeCoordinateTest, EvenLineOrientation2)
{
  cPoint<double> pointA(2, 2);
  cPoint<double> pointB(1, 1);
  EXPECT_EQ(1, rOddOffsetDistance(pointA, pointB));

  pointB = cPoint<double>(1, 0);
  EXPECT_EQ(2, rOddOffsetDistance(pointA, pointB));
}

TEST_F(HexCubeCoordinateTest, EvenLineOrientation3)
{
  cPoint<double> pointA(2, 2);
  cPoint<double> pointB(1, 2);
  EXPECT_EQ(1, rOddOffsetDistance(pointA, pointB));

  pointB = cPoint<double>(0, 2);
  EXPECT_EQ(2, rOddOffsetDistance(pointA, pointB));
}

TEST_F(HexCubeCoordinateTest, EvenLineOrientation4)
{
  cPoint<double> pointA(2, 2);
  cPoint<double> pointB(1, 3);
  EXPECT_EQ(1, rOddOffsetDistance(pointA, pointB));

  pointB = cPoint<double>(1, 4);
  EXPECT_EQ(2, rOddOffsetDistance(pointA, pointB));
}

TEST_F(HexCubeCoordinateTest, EvenLineOrientation5)
{
  cPoint<double> pointA(2, 2);
  cPoint<double> pointB(2, 3);
  EXPECT_EQ(1, rOddOffsetDistance(pointA, pointB));

  pointB = cPoint<double>(3, 4);
  EXPECT_EQ(2, rOddOffsetDistance(pointA, pointB));
}

TEST_F(HexCubeCoordinateTest, RoundTripConversion)
{
  cPoint<int> pointA(1, 3);
  EXPECT_EQ(pointA, roffsetFromCube(ODD, roffsetToCube(ODD, pointA.GetX(), pointA.GetY())));
}

TEST_F(HexCubeCoordinateTest, HexNeighborOrientation0)
{
  cPoint<int> pointB(3, 2);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 0;
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 1)));
  pointB = cPoint<int>(4, 2);
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 2)));
}

TEST_F(HexCubeCoordinateTest, HexNeighborOrientation1)
{
  cPoint<int> pointB(2, 1);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 1;
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 1)));
  pointB = cPoint<int>(3, 0);
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 2)));
}

TEST_F(HexCubeCoordinateTest, HexNeighborOrientation2)
{
  cPoint<int> pointB(1, 1);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 2;
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 1)));
  pointB = cPoint<int>(1, 0);
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 2)));
}

TEST_F(HexCubeCoordinateTest, HexNeighborOrientation3)
{
  cPoint<int> pointB(1, 2);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 3;
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 1)));
  pointB = cPoint<int>(0, 2);
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 2)));
}

TEST_F(HexCubeCoordinateTest, HexNeighborOrientation4)
{
  cPoint<int> pointB(1, 3);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 4;
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 1)));
  pointB = cPoint<int>(1, 4);
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 2)));
}

TEST_F(HexCubeCoordinateTest, HexNeighborOrientation5)
{
  cPoint<int> pointB(2, 3);
  const int xPos = 2;
  const int yPos = 2;
  const int direction = 5;
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 1)));
  pointB = cPoint<int>(3, 4);
  EXPECT_EQ(pointB, roffsetFromCube(HexCubeCoordinate::ODD,
                                    HexNeighbor(roffsetToCube(HexCubeCoordinate::ODD, xPos, yPos), direction, 2)));
}
