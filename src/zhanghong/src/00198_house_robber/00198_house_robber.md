## 198. House Robber[Easy]

>   You  are a professional robber planning to rob houses along a street. Each  house has a certain amount of money stashed, the only constraint  stopping you from robbing each of them is that adjacent houses have  security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

>   Given a list of non-negative integers representing the amount of  money of each house, determine the maximum amount of money you can rob  tonight **without alerting the police**.

**Example 1:**

```
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```
Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
```

### Solution Analysis
**Dynamic Programming**

-   Time: O(n)
-   Space: O(n)
-   Result: AC

>   `dp[i+1] = max{dp[i], dp[i-1] + nums[i+1]};`
>
>   `dp[i] = nums[i]`, `i = 0, 1;`

```c++
class Solution {
public:
    int rob(vector<int>& nums) {  
        if (nums.empty()) return 0;
        
        int cur_max = nums.front();
        vector<int> dp(nums.size());        
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            cur_max = max(cur_max, nums.at(i));
            dp.at(i) = cur_max;
        }
        
        for (size_t i = 2; i < nums.size(); i++)
        {
            dp.at(i) = max(dp.at(i-1), dp.at(i-2) + nums.at(i));
        }
        
        return dp.back();        
    }
};
```

**Space optimize**

```c++
int robber(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int pre = 0, cur = 0;
    for (int i = 0; i < nums.size(); i++) {
        int temp = max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    return cur;
}
```

