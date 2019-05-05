#include "gtest/gtest.h"

#include "00072_edit_distance.h"

class SolutionTest72 : public ::testing::Test {
protected:
    Solution72::Solution sol;
};

TEST_F(SolutionTest72, Example1)
{
    EXPECT_EQ(3, sol.minDistance("horse", "ros"));
}

TEST_F(SolutionTest72, Example2)
{
    EXPECT_EQ(5, sol.minDistance("intention", "execution"));
}




