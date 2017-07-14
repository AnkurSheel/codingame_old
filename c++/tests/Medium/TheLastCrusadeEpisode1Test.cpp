#include "Medium/TheLastCrusadeEpisode1.h"
#include "gtest/gtest.h"

class TheLastCrusadeEpisode1Test : public ::testing::Test
{
public:
  TheLastCrusadeEpisode1Test()
    : m_newColumn(0)
    , m_newRow(0)
  {
  }

private:
  virtual void SetUp() override
  {
    m_newRow = 1;
    m_newColumn = 1;
  }

  virtual void TearDown() override {}
protected:
  int m_newColumn;
  int m_newRow;
};

TEST_F(TheLastCrusadeEpisode1Test, GridType1Top)
{
  TheLastCrusadeEpisode1::GetNextPos(1, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType1Left)
{
  TheLastCrusadeEpisode1::GetNextPos(1, "LEFT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType1Right)
{
  TheLastCrusadeEpisode1::GetNextPos(1, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType2Left)
{
  TheLastCrusadeEpisode1::GetNextPos(2, "LEFT", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(2, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType2Right)
{
  TheLastCrusadeEpisode1::GetNextPos(2, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(0, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType3Top)
{
  TheLastCrusadeEpisode1::GetNextPos(3, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType4Top)
{
  TheLastCrusadeEpisode1::GetNextPos(4, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(0, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType4Right)
{
  TheLastCrusadeEpisode1::GetNextPos(4, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType5Top)
{
  TheLastCrusadeEpisode1::GetNextPos(5, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(2, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType5Left)
{
  TheLastCrusadeEpisode1::GetNextPos(5, "LEFT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType6Left)
{
  TheLastCrusadeEpisode1::GetNextPos(6, "LEFT", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(2, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType6Right)
{
  TheLastCrusadeEpisode1::GetNextPos(6, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(0, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType7Top)
{
  TheLastCrusadeEpisode1::GetNextPos(7, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType7Right)
{
  TheLastCrusadeEpisode1::GetNextPos(7, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType8Left)
{
  TheLastCrusadeEpisode1::GetNextPos(8, "LEFT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType8Right)
{
  TheLastCrusadeEpisode1::GetNextPos(8, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType9Top)
{
  TheLastCrusadeEpisode1::GetNextPos(9, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType9Left)
{
  TheLastCrusadeEpisode1::GetNextPos(9, "LEFT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType10Top)
{
  TheLastCrusadeEpisode1::GetNextPos(10, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(0, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType11Top)
{
  TheLastCrusadeEpisode1::GetNextPos(11, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(1, m_newRow);
  EXPECT_EQ(2, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType12Right)
{
  TheLastCrusadeEpisode1::GetNextPos(12, "RIGHT", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}

TEST_F(TheLastCrusadeEpisode1Test, GridType13Left)
{
  TheLastCrusadeEpisode1::GetNextPos(13, "TOP", m_newColumn, m_newRow);
  EXPECT_EQ(2, m_newRow);
  EXPECT_EQ(1, m_newColumn);
}
