#include "01451_rearrange_words_in_a_sentence.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test
{
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    string param{"Leetcode is cool"};
    EXPECT_EQ("Is cool leetcode", sol.arrangeWords(param));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ("On and keep calm code", sol.arrangeWords("Keep calm and code on"));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ("To be or to be not", sol.arrangeWords("To be or not to be"));
}
