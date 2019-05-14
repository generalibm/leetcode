#include "00087_scramble_string.h"

#include "gtest/gtest.h"

class SolutionTest87 : public ::testing::Test {
protected:
    Solution87::Solution sol;
};
#if 1
TEST_F(SolutionTest87, Example1)
{
    EXPECT_TRUE(sol.isScramble("great", "rgeat"));
}


TEST_F(SolutionTest87, Example2)
{
    EXPECT_FALSE(sol.isScramble("abcde", "caebd"));
}
#endif

TEST_F(SolutionTest87, WrongAnswer1)
{
    EXPECT_FALSE(sol.isScramble("dbdac","abcdd"));
}

