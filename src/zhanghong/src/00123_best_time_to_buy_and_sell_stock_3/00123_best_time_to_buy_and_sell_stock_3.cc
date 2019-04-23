#include "00123_best_time_to_buy_and_sell_stock_3.h"

#include <vector>
#include <queue>
#include <functional>

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
int Solution::maxProfit(const vector<int>& prices)
{
    if (prices.size() < 2)
        return 0;

    int max = maxProfitInrange(prices.data(), 0, prices.size()-1);


    for (int i = 0; i < prices.size() -1; i++)
    {
        max = std::max(max, maxProfitInrange(prices.data(), 0, i) + maxProfitInrange(prices.data(), i+1, prices.size() -1));
    }

    return max;
}
