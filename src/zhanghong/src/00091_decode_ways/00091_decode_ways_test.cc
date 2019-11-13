#include "gtest/gtest.h"

#include "00091_decode_ways.h"

using namespace Solution91;

class SolutionTest91 : public ::testing::Test
{
protected:
    Solution sol;
};
#if 1
TEST_F(SolutionTest91, Example1)
{
    EXPECT_EQ(2, sol.numDecodings("12"));
}
#endif
TEST_F(SolutionTest91, Example2)
{
    EXPECT_EQ(3, sol.numDecodings("126"));
}

TEST_F(SolutionTest91, BoundryTest)
{
    EXPECT_EQ(43046721, sol.numDecodings("126126126126126126126126126126126126126126126126"));
}

TEST_F(SolutionTest91, WrongAnswer1)
{
    EXPECT_EQ(1, sol.numDecodings("10"));
}





