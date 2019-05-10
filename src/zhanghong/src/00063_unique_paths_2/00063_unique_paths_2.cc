#include "00063_unique_paths_2.h"

int Solution63::Solution::uniquePathsWithObstacles(
        const vector<vector<int>>& obstacleGrid)
{
    if (obstacleGrid.empty()) return 0;

    const size_t len_row = obstacleGrid.size();
    const size_t len_col = obstacleGrid[0].size();

    vector<vector<long>>
    dp(len_row, vector<long>(len_col));

    // the first column
    for (size_t i = 0; i < len_row; i++)
    if (obstacleGrid[i][0] == 0)
    {
        dp[i][0] = 1;
    }
    else if (obstacleGrid[i][0] == 1)
    {
        dp[i][0] = 0;
        break;
    }

    // the first row
    for (size_t i = 0; i < len_col; i++)
    if (obstacleGrid[0][i] == 0)
    {
        dp[0][i] = 1;
    }
    else if(obstacleGrid[0][i] == 1)
    {
        dp[0][i] = 0; break;
    }

    for (size_t i = 1; i < len_row; i++)
    {
        for (size_t j = 1; j < len_col; j++)
        {
            dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[len_row-1][len_col-1];
}

