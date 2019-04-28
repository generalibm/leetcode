## 122. Best Time to Buy and Sell Stock II[Easy]

> Say you have an array for which the ith element is the price of a given stock on day i.

> Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

> Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example 1:**

- Input: `[7,1,5,3,6,4]`
- Output: `7`
- Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

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

- Brute-force Approach(**time overflow**)

> The idea is to find all the first reverse pair and starting from it to find the next one,..., etc, 

- Time: O(n^n) 

- Divide and conquer(**wrong answer**)

> If we divide the problem into two equal parts, we would to campare the two subproblems and the cross one, which would not be able to merge since it would have more than 2 parts. For example: `1, 2, 4, 2, 5, 7, 2, 4, 9, 0` could be divided into `1, 2, 4, 2, 5,` and ` 7, 2, 4, 9, 0`, then we would solve the cross scenario that can not be merge from `1, 2, 4, 2, 5,` and ` 7, 2, 4, 9, 0` parts to choose the biggest one (`9`)in the right and the smallest one(`1`) in the left part and simplily add them together which is `8`, because the solution is three parts `1, 2, 4,`, `2, 5, 7,`, and ` 2, 4, 9, 0`.


- **Greedy **
> Just calculate from the begin to the end;
- Time : O(n)
- Space: O(1)
