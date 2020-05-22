#include "00451_sort_characters_by_frequence.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ("eert", sol.frequencySort("tree"));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ("cccaaa", sol.frequencySort("cccaaa"));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ("bbAa", sol.frequencySort("Aabb"));
}