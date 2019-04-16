#include <gtest/gtest.h>

#include "00005_longest_palindromic_substring.h"

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, SingleCharacterPalindrome)
{
    EXPECT_EQ(true, sol.isPalindromic("a"));
}

TEST_F(SolutionTest, TwoDuplicatedLettersPalindrome)
{
    EXPECT_EQ(true, sol.isPalindromic("aa"));
}

TEST_F(SolutionTest, NormalPalinDrome)
{
    EXPECT_EQ(true, sol.isPalindromic("aba"));
    EXPECT_EQ(true, sol.isPalindromic("abba"));
    EXPECT_EQ(false, sol.isPalindromic("abab"));
}

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ("bab", sol.longestPalindrome("babad"));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ("bb", sol.longestPalindrome("cbbd"));
}
