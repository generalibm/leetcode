#include "gtest/gtest.h"

#include "00051_n_queens.h"

class SolutionTest51 : public ::testing::Test {
protected:
    Solution51::Solution sol;
};

TEST_F(SolutionTest51, example1)
{
    vector<vector<string>> param{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}};

    EXPECT_EQ(param, sol.solveNQueens(4));
}