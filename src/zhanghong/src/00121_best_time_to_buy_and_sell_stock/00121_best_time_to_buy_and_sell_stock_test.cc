#include "gtest/gtest.h"

#include "00121_best_time_to_buy_and_sell_stock.h"

namespace SolutionTest_000122 {

class SolutionTest00121: public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest00121, Example1)
{
    EXPECT_EQ(5, sol.maxProfit( { 7, 1, 5, 3, 6, 4 }));
}

TEST_F(SolutionTest00121, Example2)
{
    EXPECT_EQ(0, sol.maxProfit( { 7, 6, 4, 3, 1 }));
}


}


