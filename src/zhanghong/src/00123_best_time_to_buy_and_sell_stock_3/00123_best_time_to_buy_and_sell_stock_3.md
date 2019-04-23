## 123. Best Time to Buy and Sell Stock III[Hard]

> Say you have an array for which the ith element is the price of a given stock on day i.

> Design an algorithm to find the maximum profit. You may complete at most two transactions.

> Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example 1:**

- Input: `[3,3,5,0,0,3,1,4]`
- Output: `6`
- Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

**Example 2:**

- Input: `[1,2,3,4,5]`
- Output: `4`
- Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.

**Example 3:**

- Input: `[7,6,4,3,1]`
- Output: `0`
- Explanation: In this case, no transaction is done, i.e. max profit = 0.


**Solution Analysis**

- **Brute-force Approach**

> The idea is to find all the reverse pairs and then pick up the biggest two. We should make sure the two do not cover each other, which is much hard.

> BUT, we could get max profix for every two divided parts in `O(n)`, the total is `O(n^2)`, and compare it to original problem which is `O(n)`

```c++
int maxProfit(vector<int>& prices) {
    if (prices.size() < 2)
    		return 0;
    		
    int max = maxProfitInrange(prices.data(), 0, prices.size()-1);

    for (int i = 0; i < prices.size() -1; i++)
    {
        max = std::max(max, maxProfitInrange(prices.data(), 0, i) + maxProfitInrange(prices.data(), i+1, prices.size() -1));
    }

    		return max;
    }
    
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
```

- Time 		: O(n^2)
- Space		: O(1)
- Result 	: Time Limit Exceeded

- **Dynamic Programming**

> Note that we would get max profix for the subproblem in `O(1)` not `O(n)`, which would decrease the time complexity to `O(n)`. 

> Image that when we have the solution of `{i, ..., j}`, we could get `{i, ..., j, j+1}` in `O(1)` , For example: `{3, 3, 5, 0, 0, 3, 1}` (profix = 3, max_indicator = 3, min_indicator = 0), when `4` is goning to be added into the set `{3, 3, 5, 0, 0, 3, 1, 4}`, we just need to update the *max_indicator* and *min_indicator*, here we just update `max_indicator = 4` ; Actually the profit always equals to  `max_indicator - min_indicator`.

```c++
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
// Space    : O(1)
// Result   : Time limit Exceeded
int maxProfit(const vector<int>& prices)
{
    if (prices.size() < 2)
        return 0;

    vector<int> dp = getDP(prices);
    vector<int> dp_reverse = getReverseDP(prices);

    int max = 0;

    for (int i = 0 ; i < dp.size() - 1; i++)
    {
        max = std::max(max, dp[i] + dp_reverse[i+1]);
    }

    return max;
}

```

- Time 		: O(n)
- Space		: O(n)
- Result 	: AC
