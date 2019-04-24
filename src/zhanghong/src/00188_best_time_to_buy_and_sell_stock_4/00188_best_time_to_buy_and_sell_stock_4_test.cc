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
