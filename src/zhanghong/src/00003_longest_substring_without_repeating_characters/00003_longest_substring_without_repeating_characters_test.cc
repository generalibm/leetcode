
#include <gtest/gtest.h>

#include "00003_longest_substring_without_repeating_characters.h"

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("abcabcbb"));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(1, sol.lengthOfLongestSubstring("bbbbb"));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("pwwkew"));
}

TEST_F(SolutionTest, EmptyString)
{
    EXPECT_EQ(0, sol.lengthOfLongestSubstring(""));
}

TEST_F(SolutionTest, String)
{
    EXPECT_EQ(2, sol.lengthOfLongestSubstring("au"));
}
