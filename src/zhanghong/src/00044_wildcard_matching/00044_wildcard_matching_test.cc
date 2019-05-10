#include "gtest/gtest.h"

#include "00044_wildcard_matching.h"

class SolutionTest: public ::testing::Test {
protected:
    Solution44::Solution sol;
};

#if 1
TEST_F(SolutionTest, Example1)
{
    EXPECT_FALSE(sol.isMatch("aa", "a"));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_TRUE(sol.isMatch("aa", "*"));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_FALSE(sol.isMatch("cb", "?a"));
}

TEST_F(SolutionTest, Example4)
{
    EXPECT_TRUE(sol.isMatch("adceb", "*a*b"));
}

TEST_F(SolutionTest, Example5)
{
    EXPECT_FALSE(sol.isMatch("acdcb", "a*c?b"));
}

TEST_F(SolutionTest, TimeLimitedExceeded1)
{
    EXPECT_TRUE(sol.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba",
                    "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*"));
}

TEST_F(SolutionTest, WrongAnswer1)
{
    EXPECT_TRUE(sol.isMatch("ho", "ho**"));
}
#endif
TEST_F(SolutionTest, WrongAnswer2)
{
    EXPECT_FALSE(sol.isMatch("mississippi", "m??*ss*?i*pi"));
}

TEST_F(SolutionTest, TimeLimitedExceeded2)
{
    EXPECT_FALSE(
            sol.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",
                    "a*******b"));
}

