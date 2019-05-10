#include "00072_edit_distance.h"

#include <vector>

// Dynamic programming Approach
// Time     : O(mn)
// Space    : O(mn)
// Result   : AC

#if 0
int Solution72::Solution::minDistance(string word1, string word2)
{
    size_t m = word1.size();
    size_t n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (size_t i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }

    for (size_t j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (size_t i = 1; i <= m; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = std::min(dp[i - 1][j - 1],
                        std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    return dp[m][n];
}
#endif

// Dynamic programming Approach - space depress
// Time     : O(mn)
// Space    : O(n)
// Result   : AC
int Solution72::Solution::minDistance(string word1, string word2)
{
    size_t m = word1.size();
    size_t n = word2.size();
    vector<int> cur(n+1, 0);
    for (size_t i = 1; i <= n;i++)
    {
        cur[i] = i;
    }

    int pre;
    for (size_t i = 1; i <= m; i++)
    {
        pre = cur[0];

        cur[0] = i;// equal to first column

        for (size_t j = 1; j <= n; j++)
        {
            int temp = cur[j];

            if (word1[i-1] == word2[j-1])
            {
                cur[j] = pre;
            }
            else
            {
                cur[j] = std::min(pre, std::min(cur[j-1],cur[j])) + 1;
            }

            pre = temp;
        }
    }

    return cur[n];
}
