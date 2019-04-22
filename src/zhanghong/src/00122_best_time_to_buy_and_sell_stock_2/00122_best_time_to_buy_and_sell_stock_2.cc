#include "00122_best_time_to_buy_and_sell_stock_2.h"

int Solution::maxProfit(const vector<int>& prices)
{
    if (prices.size() < 2) return 0;

    int max = 0;
    int res = 0;
    int min = prices.front();
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < prices[i-1])
        {
            min = prices[i];
            res += max;
            max = 0;
        }

        max = std::max(max, prices[i] - min);

        if (prices[i] < min)
            min = prices[i];
    }

    return std::max(max, res+max);
}

