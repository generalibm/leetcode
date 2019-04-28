#include "gtest/gtest.h"

#include "00122_best_time_to_buy_and_sell_stock_2.h"

namespace SolutionTest_000122 {

class SolutionTest00122: public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest00122, Example1)
{
    EXPECT_EQ(7, sol.maxProfit( { 7, 1, 5, 3, 6, 4 }));
}

TEST_F(SolutionTest00122, Example2)
{
    EXPECT_EQ(4, sol.maxProfit( { 1, 2, 3, 4, 5 }));
}

TEST_F(SolutionTest00122, Example3)
{
    EXPECT_EQ(0, sol.maxProfit( { 7, 6, 4, 3, 1 }));
}

TEST_F(SolutionTest00122, WrongAnswer)
{
    EXPECT_EQ(8, sol.maxProfit( { 3, 3, 5, 0, 0, 3, 1, 4 }));
}

TEST_F(SolutionTest00122, WrongAnswer2)
{
    EXPECT_EQ(15, sol.maxProfit( { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 }));
}

}
