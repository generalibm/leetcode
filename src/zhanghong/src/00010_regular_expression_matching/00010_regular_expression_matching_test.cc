#include "00010_regular_expression_matching.h"

#include "gtest/gtest.h"

using namespace Solution10;

class SololutionTest10 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SololutionTest10, Example1)
{
    EXPECT_FALSE(sol.isMatch("aa", "a"));
}

TEST_F(SololutionTest10, Example2)
{
    EXPECT_TRUE(sol.isMatch("aa", "a*"));
}

TEST_F(SololutionTest10, Example3)
{
    EXPECT_TRUE(sol.isMatch("ab", ".*"));
}

TEST_F(SololutionTest10, Example4)
{
    EXPECT_TRUE(sol.isMatch("aab", "c*a*b"));
}

TEST_F(SololutionTest10, Example5)
{
    EXPECT_FALSE(sol.isMatch("mississippi", "mis*is*p*."));
}

TEST_F(SololutionTest10, WrongAnswer1)
{
    EXPECT_FALSE(sol.isMatch("ab", ".*c"));
}

