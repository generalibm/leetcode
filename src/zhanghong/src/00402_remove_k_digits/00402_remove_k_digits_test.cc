#include "00402_remove_k_digits.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test
{
protected:
    Solution sol;
};

// TEST_F(SolutionTest, Boundary1)
// {
//     EXPECT_EQ("0", sol.removeKdigits("10",2));
// }

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ("1219", sol.removeKdigits("1432219",3));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ("200", sol.removeKdigits("10200",1));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ("0", sol.removeKdigits("10",2));
}

TEST_F(SolutionTest, WrongAnswer1)
{
    EXPECT_EQ("1321", sol.removeKdigits("43214321",4));
}

