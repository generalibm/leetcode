#include "00121_best_time_to_buy_and_sell_stock.h"


//Brute-force Approach
//Time : O(n^2)
//Space: O(1)
//int Solution::maxProfit(const vector<int>& prices)
//{
//    int profix = 0;
//    for (size_t i = 0; i < prices.size(); i++)
//    {
//        for (size_t j = i; j < prices.size(); j++)
//        {
//            if (profix < prices[j] - prices[i])
//                profix = prices[j] - prices[i];
//        }
//    }
//
//    return profix;
//}


//Dynamic programming Approach
//Time : O(n)
//Space: O(1)
int Solution::maxProfit(const vector<int>& prices)
{
    if (prices.size() < 2) return 0;

    int min_elem = prices.front();
    int max_profix = 0;

    for (size_t i = 1; i < prices.size(); i++)
    {
        max_profix = std::max(prices[i] - min_elem, max_profix);
        if (prices[i] < min_elem)
            min_elem = prices[i];
    }

    return max_profix;
}



