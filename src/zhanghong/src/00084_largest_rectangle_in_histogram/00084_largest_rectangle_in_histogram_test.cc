#include "00084_largest_rectangle_in_histogram.h"

#include "gtest/gtest.h"

class SolutionTest84 : public ::testing::Test {
protected:
    Solution84::Solution sol;
};

#if 1
TEST_F(SolutionTest84, Example0)
{
    EXPECT_EQ(5, sol.largestRectangleArea({2,1,5}));
}

TEST_F(SolutionTest84, Example1)
{
    EXPECT_EQ(10, sol.largestRectangleArea({2,1,5,6,2,3}));
}

TEST_F(SolutionTest84, Example2)
{
    EXPECT_EQ(12, sol.largestRectangleArea({5,6,2,6,6}));
}

TEST_F(SolutionTest84, Example3)
{
    EXPECT_EQ(9, sol.largestRectangleArea({0,0, 1, 2, 3, 4, 5}));
}

TEST_F(SolutionTest84, Example4)
{
    EXPECT_EQ(9, sol.largestRectangleArea({5, 4, 3, 2, 1, 0, 0}));
}

TEST_F(SolutionTest84, WrongAnswer1)
{
    EXPECT_EQ(25, sol.largestRectangleArea({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST_F(SolutionTest84, WrongAnswer2)
{
    EXPECT_EQ(4, sol.largestRectangleArea( { 1, 2, 2 }));
}

TEST_F(SolutionTest84, WrongAnswer3)
{
    EXPECT_EQ(20, sol.largestRectangleArea({3,6,5,7,4,8,1,0}));
}

TEST_F(SolutionTest84, RunTimeError1)
{
    EXPECT_EQ(2147483647, sol.largestRectangleArea({2147483647,0,2147483647,0,2147483647,0,2147483647,0,2147483647,0}));
}

TEST_F(SolutionTest84, WrongAnswer4)
{
    EXPECT_EQ(1, sol.largestRectangleArea({1,0,1,0,1}));
}
#endif
TEST_F(SolutionTest84, WrongAnswer5)
{
    EXPECT_EQ(18, sol.largestRectangleArea( { 5, 4, 9, 5,3, 8, 2, 9 }));
}
