#include "00188_best_time_to_buy_and_sell_stock_4.h"

using namespace Solution188;

// Intuitive Approach based best_time_to_buy_and_sell_stock_3
// Time     : O(n^2)
// Space    : O(n^n)
// Result   : Stack Overflow
//int maxInOneRound(const int *data, int left, int right)
//{
//    if (left >= right) return 0;
//
//    int max = 0;
//    int min = data[left];
//    for (int i = left + 1; i <= right; i++)
//    {
//        max = std::max(max, data[i] - min);
//        if (data[i] < min)
//            min = data[i];
//    }
//
//    return max;
//}
//
//vector<int> getDP(const int * data, int left, int right)
//{
//    vector<int> dp(right - left + 1);
//
//    int max = 0;
//    int min = data[left];
//    for (int i = left + 1; i <= right; i++)
//    {
//        max = std::max(max, data[i] - min);
//        if (data[i] < min)
//            min = data[i];
//        dp[i] = max;
//    }
//
//    dp.insert(dp.begin(), 0);
//
//    return dp;
//}
//
//vector<int> getReverseDP(const int * data, int left, int right)
//{
//    vector<int> reverse_dp(right - left + 1 + 1);
//
//    int max = data[right];
//    int min = data[right];
//
//    int res = 0;
//
//    for (int i = right; i >= left; i--)
//    {
//        if (data[i] < min)
//            min = data[i];
//        if (max < data[i])
//        {
//            min = max = data[i];
//        }
//
//        reverse_dp[i] = std::max(res, max - min);
//    }
//
//    reverse_dp.insert(reverse_dp.begin(), 0);
//
//    return reverse_dp;
//}
//
//
//int maxInTwoRound(const int *data, int left, int right)
//{
//
//    if (left >= right)
//        return 0;
//
//    vector<int> dp = getDP(data, left, right);
//    vector<int> dp_reverse = getReverseDP(data, left, right);
//
//    int max = 0;
//
//    for (int i = 0; i < dp.size() - 1; i++)
//    {
//        max = std::max(max, dp[i] + dp_reverse[i + 1]);
//    }
//
//    return max;
//}
//
//
//int maxProfitInRange(int k, const int *data, int left, int right)
//{
//    if (left >= right) return 0;
//
//    int max = 0;
//
//    if (k == 1)
//    {
//        max = maxInOneRound(data, left, right);
//
//        return max;
//    }
//    if (k == 2)
//    {
//        max = maxInTwoRound(data, left, right);
//
//        return max;
//    }
//
//    for (int i = left; i <= right; i++)
//    {
//        max = std::max(max, maxProfitInRange(k-1, data, 0, i) + maxInOneRound(data, i+1, right));
//    }
//
//    return max;
//}
//
//
//
//int Solution::maxProfit(int k, const vector<int>& prices)
//{
//    if (prices.empty() || k >= prices.size() || k < 0) return 0;
//
//    if (prices.size() < 2) return prices.front();
//
//    return maxProfitInRange(k, prices.data(), 0, prices.size()-1);
//}


// State machine Approach
// Time     : O(n)
// Space    : O(1)
// Result   : TLE
//#include <climits>
//
//int maxInTwoRound(const int *data, int left, int right)
//{
//    if (left >= right)
//        return 0;
//
//    int s1 = -data[left], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
//
//    for (int i = left+1; i <= right; ++i)
//    {
//        s1 = max(s1, -data[i]);
//        s2 = max(s2, s1 + data[i]);
//        s3 = max(s3, s2 - data[i]);
//        s4 = max(s4, s3 + data[i]);
//    }
//    return max(0, s4);
//}
//
//int maxInOneRound(const int *data, int left, int right)
//{
//    if (left >= right) return 0;
//
//    int max = 0;
//    int min = data[left];
//    for (int i = left + 1; i <= right; i++)
//    {
//        max = std::max(max, data[i] - min);
//        if (data[i] < min)
//            min = data[i];
//    }
//
//    return max;
//}
//
//
//int maxProfitInRange(int k, const int *data, int left, int right)
//{
//    if (left >= right) return 0;
//
//    int max = 0;
//
//    if (k == 1)
//    {
//        max = maxInOneRound(data, left, right);
//
//        return max;
//    }
//    if (k == 2)
//    {
//        max = maxInTwoRound(data, left, right);
//
//        return max;
//    }
//
//    for (int i = left; i <= right; i++)
//    {
//        max = std::max(max, maxProfitInRange(k-1, data, 0, i) + maxInOneRound(data, i+1, right));
//    }
//
//    return max;
//}
//
//int Solution::maxProfit(int k, const vector<int>& prices)
//{
//    if (prices.size() < 2 || k >= prices.size() || k <= 0) return 0;
//
//    return maxProfitInRange(k, prices.data(), 0, prices.size()-1);
//}

#include <climits>
int Solution::maxProfit(int k, const vector<int>& prices)
{
    if (prices.size() < 2 || k <= 0) return 0;

    if (k >= prices.size()/2)
    {
        int max = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            max += std::max(0, prices[i]-prices[i-1]);
        }
        return max;
    }

    vector<int> hold(k+1);
    vector<int> rele(k+1);

    for (size_t i = 0; i <=k; i++)
    {
        hold[i] = INT_MIN;
        rele[i] = 0;
    }

    for (size_t i = 0; i < prices.size(); i++)
    {
        for (int j = k; j > 0; j--)
        {
            rele[j] = max(rele[j], hold[j] + prices[i]);
            hold[j] = max(hold[j], rele[j-1] - prices[i]);
        }
    }

    return rele[k];
}

