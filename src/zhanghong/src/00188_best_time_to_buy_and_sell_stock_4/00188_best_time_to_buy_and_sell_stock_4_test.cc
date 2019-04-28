#include "gtest/gtest.h"

#include "00188_best_time_to_buy_and_sell_stock_4.h"

using namespace Solution188;

class SolutionTest188: public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest188, Example1)
{
    EXPECT_EQ(2, sol.maxProfit(2, { 2, 4, 1 }));
}

TEST_F(SolutionTest188, Example2)
{
    EXPECT_EQ(7, sol.maxProfit(2, { 3, 2, 6, 5, 0, 3 }));
}

TEST_F(SolutionTest188, StackOverFlow1)
{
    EXPECT_EQ(0, sol.maxProfit(0, { 1, 3 }));
}

TEST_F(SolutionTest188, TimeLimitExceeded1)
{
EXPECT_EQ(482, sol.maxProfit(11,
                {48,12,60,93,97,42,25,64,17,56,85,93,9,48,52,42,58,85,81,84,69,36,1,54,23,15,72,15,11,94}))
;
}

