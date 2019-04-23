#include "gtest/gtest.h"

#include "00123_best_time_to_buy_and_sell_stock_3.h"

using namespace Solution123;

class SolutionTest123 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest123, Example1)
{
    EXPECT_EQ(6, sol.maxProfit({3,3,5,0,0,3,1,4}));
}

TEST_F(SolutionTest123, Example2)
{
    EXPECT_EQ(4, sol.maxProfit({1,2,3,4,5}));
}

TEST_F(SolutionTest123, Example3)
{
    EXPECT_EQ(0, sol.maxProfit({7,6,4,3,1}));
}

TEST_F(SolutionTest123, WrongAnswer1)
{
    EXPECT_EQ(3, sol.maxProfit( { 1, 4, 2 }));
}

TEST_F(SolutionTest123, WrongAnswer2)
{
    EXPECT_EQ(13, sol.maxProfit( { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 }));
}
