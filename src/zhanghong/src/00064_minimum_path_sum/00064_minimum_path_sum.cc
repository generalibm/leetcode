#include "00064_minimum_path_sum.h"

int Solution64::Solution::minPathSum(const vector<vector<int>>& grid)
{
    if (grid.empty())
        return 0;

    size_t len_row = grid.size();
    size_t len_col = grid[0].size();

    vector<vector<long>> dp(len_row, vector<long>(len_col));
    dp[0][0] = grid[0][0];

    for (size_t i = 1; i < len_col; i++)
        dp[0][i] = grid[0][i] + dp[0][i - 1];
    for (size_t j = 1; j < len_row; j++)
        dp[j][0] = grid[j][0] + dp[j - 1][0];

    for (size_t i = 1; i < len_row; i++)
    {
        for (size_t j = 1; j < len_col; j++)
        {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp[len_row - 1][len_col - 1];
}

