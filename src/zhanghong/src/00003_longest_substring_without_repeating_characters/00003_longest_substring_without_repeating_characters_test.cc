
#include <gtest/gtest.h>

#include "00003_longest_substring_without_repeating_characters.h"

namespace Solution_0003 {


class Solution0003 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(Solution0003, Example1)
{
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("abcabcbb"));
}

TEST_F(Solution0003, Example2)
{
    EXPECT_EQ(1, sol.lengthOfLongestSubstring("bbbbb"));
}

TEST_F(Solution0003, Example3)
{
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("pwwkew"));
}

TEST_F(Solution0003, EmptyString)
{
    EXPECT_EQ(0, sol.lengthOfLongestSubstring(""));
}

TEST_F(Solution0003, String)
{
    EXPECT_EQ(2, sol.lengthOfLongestSubstring("au"));
}

};
