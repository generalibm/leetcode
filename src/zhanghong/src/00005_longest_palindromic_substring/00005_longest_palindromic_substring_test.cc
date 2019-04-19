#include <gtest/gtest.h>

#include "00005_longest_palindromic_substring.h"

namespace SolutionTest_00005 {

class SolutionTest00005 : public ::testing::Test {
protected:
    Solution sol;
};

//TEST_F(SolutionTest, SingleCharacterPalindrome)
//{
//    EXPECT_EQ(true, sol.isPalindromic("a"));
//}
//
//TEST_F(SolutionTest, TwoDuplicatedLettersPalindrome)
//{
//    EXPECT_EQ(true, sol.isPalindromic("aa"));
//}
//
//TEST_F(SolutionTest, NormalPalinDrome)
//{
//    EXPECT_EQ(true, sol.isPalindromic("aba"));
//    EXPECT_EQ(true, sol.isPalindromic("abba"));
//    EXPECT_EQ(false, sol.isPalindromic("abab"));
//}

TEST_F(SolutionTest00005, Example1)
{
    EXPECT_EQ("bab", sol.longestPalindrome("babad"));
}

TEST_F(SolutionTest00005, Example2)
{
    EXPECT_EQ("bb", sol.longestPalindrome("cbbd"));
}

TEST_F(SolutionTest00005, EmptyString)
{
    EXPECT_EQ("", sol.longestPalindrome(""));
}

TEST_F(SolutionTest00005, OnlyOneChar)
{
    EXPECT_EQ("b", sol.longestPalindrome("b"));
}

TEST_F(SolutionTest00005, DiffTwoChar)
{
    EXPECT_EQ("b", sol.longestPalindrome("bd"));
}

TEST_F(SolutionTest00005, AllPalindrome)
{
    EXPECT_EQ("abcba", sol.longestPalindrome("abcba"));
}

};
