## 901. Online Stock Span[Medium]

Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

**Example 1:**
- Input: ["StockSpanner","next","next","next","next","next","next","next"], [[],[100],[80],[60],[70],[60],[75],[85]]
- Output: [null,1,1,1,2,1,4,6]
- Explanation: 
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
 
***Note:***
- Calls to StockSpanner.next(int price) will have 1 <= price <= 10^5.
- There will be at most 10000 calls to StockSpanner.next per test case.
- There will be at most 150000 calls to StockSpanner.next across all test cases.
- The total time limit for this problem has been reduced by 75% for C++, and 50% for all other languages.

## Solution Analysis
### Approach 1 - brute force
**Strategy:**
**Explanation:**

**Cpp code:**
```c++
class StockSpanner {
public:
    StockSpanner() : prices() {}

    int next(int price)
    {
        if (prices.empty() || prices.back > price) 
        {
            /// It would be TLE if there are not these lines.
            /// Since I found that it failed in 99/99 test cases, 
            /// so, I realised this would work.
            prices.push_back(price);
            return 1;
        }

        int cnt = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] <= price) ++cnt;
            else break;
        }

        return cnt;
    }
private:
    vector<int> prices;
};
```
**Time Complexity:** O(N)
**Space Complexity:** O(1)
**Result:** AC(1896ms)

### Approach 2 - optimized from apporach 1 with a stack
**Strategy:** 
**Explanation:**
```json

    |                       
    |                   |
    |              |    |                   |
    |         |    |    |                   |
    |    |    |    |    |              |    |                   |                   |
    |    |    |    |    |              |    |              |    |              |    |
    |    |    |    |    |         |    |    |         |    |    |         |    |    |
    |    |    |    |    |         |    |    |    |    |    |    |    |    |    |    |
    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |   
        \            /      \            /      \            /      \            /
         -----3------        -----3------        -----3------        -----3------       All of these would be ignored, so that could reduce time    
```
**Cpp code:**
```c++
class StockSpanner {
public:
    StockSpanner() : prices(), weights() {}

    int next(int price)
    {
        if (prices.empty() || prices.top() > price)
        {
            prices.push(price);
            weights.push(1);

            return 1;
        }

        int w = 1;
        while (!prices.empty() && prices.top() <= price)
        {
            w += weights.top();
            weights.pop();
            prices.pop();
        }
        weights.push(w);
        prices.push(price);

        return w;
    }

private:
    stack<int> prices;
    stack<int> weights;
};
```

**Time Complexity:** O(K) = omega(N), where k is the number of the elements that are less than the current `price`.
**Space Complexity:** O(M) = omega(N), where M is the the number of the elements that are greater than the current `price`.
**Result:** AC(460ms)
