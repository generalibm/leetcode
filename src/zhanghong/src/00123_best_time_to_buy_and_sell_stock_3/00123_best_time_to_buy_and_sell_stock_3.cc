#include "00123_best_time_to_buy_and_sell_stock_3.h"

#include <vector>
#include <algorithm>

using namespace std;
using namespace Solution123;

int maxProfitInrange(const int * data, int left, int right)
{
    if (left >= right) return 0;

    int min = data[left];

    int max = 0;
    for (int i = left+1; i <= right; i++)
    {
        max = std::max(max, data[i] - min);

        if (data[i] < min)
            min = data[i];
    }

    return max;
}

// Brute-force Approach
// Time     : O(n^2)
// Space    : O(1)
// Result   : Time limit Exceeded
//int Solution::maxProfit(const vector<int>& prices)
//{
//    if (prices.size() < 2)
//        return 0;
//
//    int max = maxProfitInrange(prices.data(), 0, prices.size()-1);
//
//
//    for (int i = 0; i < prices.size() -1; i++)
//    {
//        max = std::max(max, maxProfitInrange(prices.data(), 0, i) + maxProfitInrange(prices.data(), i+1, prices.size() -1));
//    }
//
//    return max;
//}



vector<int> getDP(const vector<int> & data)
{
    vector<int> dp(data.size());

    int max = 0;
    int min = data.front();
    for (int i = 1; i < data.size(); i++)
    {
        max = std::max(max, data[i] - min);
        if (data[i] < min)
            min = data[i];
        dp[i] = max;
    }
    dp.insert(dp.begin(), 0);
    return dp;
}

vector<int> getReverseDP(const vector<int> & data)
{
    vector<int> reverse_dp(data.size() + 1);

    int max = data.back();
    int min = data.back();

    int res = 0;

    for (int i = data.size() - 1; i >= 0; i--)
    {
        if (data[i] < min)
            min = data[i];
        if (max < data[i])
        {
            min = max = data[i];
        }

        reverse_dp[i] = std::max(res, max - min);
    }

    reverse_dp.insert(reverse_dp.begin(), 0);

    return reverse_dp;
}



// Brute-force Approach optimization
// Time     : O(n)
// Space    : O(n)
// Result   : AC
//int Solution::maxProfit(const vector<int>& prices)
//{
//    if (prices.size() < 2)
//        return 0;
//
//    vector<int> dp = getDP(prices);
//    vector<int> dp_reverse = getReverseDP(prices);
//
//    int max = 0;
//
//    for (int i = 0 ; i < dp.size() - 1; i++)
//    {
//        max = std::max(max, dp[i] + dp_reverse[i+1]);
//    }
//
//    return max;
//}

// Dynamic Programming Approach
// Time     : O(n)
// Space    : O(1)
// Result   : AC
#include <climits>
int Solution::maxProfit(const vector<int>& prices)
{
    if (prices.empty()) return 0;

    int s1 = -prices.front();
    int s2 = INT_MIN;
    int s3 = INT_MIN;
    int s4 = INT_MIN;

    for (size_t i = 1; i < prices.size(); i++)
    {
        s1 = max(s1, -prices[i]);
        s2 = max(s2, s1 + prices[i]);
        s3 = max(s3, s2 - prices[i]);
        s4 = max(s4, s3 + prices[i]);
    }

    return max(0, s4);
}
