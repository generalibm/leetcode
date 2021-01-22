#include "calculate_money_in_leetcode_bank.h"

#include "gtest/gtest.h"

class SolutionBiweeklyContest43Test : public ::testing::Test {
    protected:
    Solution sol;
};

TEST_F(SolutionBiweeklyContest43Test, Example1)
{
    EXPECT_EQ(10, sol.totalMoney(4));
}


TEST_F(SolutionBiweeklyContest43Test, Example2)
{
    EXPECT_EQ(37, sol.totalMoney(10));
}


TEST_F(SolutionBiweeklyContest43Test, Example3)
{
    EXPECT_EQ(96, sol.totalMoney(20));
}