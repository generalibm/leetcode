#include "gtest/gtest.h"

#include "00062_unique_paths.h"

class SolutionTest : public ::testing::Test {
protected:
    Solution62::Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(3, sol.uniquePaths(3, 2));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(28, sol.uniquePaths(7, 3));
}

TEST_F(SolutionTest, WrongAnswer1)
{
    EXPECT_EQ(1, sol.uniquePaths(1, 1));
}





