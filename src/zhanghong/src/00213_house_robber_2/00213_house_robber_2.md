## 213. House Robber II[Medium]

>   You  are a professional robber planning to rob houses along a street. Each  house has a certain amount of money stashed. All houses at this place  are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

>   Given a list of non-negative integers representing the amount of  money of each house, determine the maximum amount of money you can rob  tonight **without alerting the police**.

**Example 1:**

```
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
```

**Example 2:**

```
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
```

### Solution Analysis

**Dynamic Programming**

-   Time: O(n)

-   Space: O(n)

-   Result: AC

>   Notice that the difference between *house robber 1* and *house robber 2* is **sequence order**, here, it arrange as a circle, which means the last element and first one would be meet the case in like the Example 1.
>
>   In order to detect this case, we just need a variable(`isFirst`) to memory it whether we calculated from the first element in `nums` or not. 
>
>   **case 1**
>
>   | i       | 0    | 1     | 2    | 3    |
>   | ------- | ---- | ----- | ---- | ---- |
>   | nums    | 1 | 2 | 3 | 1 |
>   | dp      | 1 | 2 | 4 | <u>4</u> |
>   | isFirst | true | false | true  |<u>true</u> |
>   	or 
>   **case 2**
>
>   | i       | 0    | 1     | 2     | 3     | 4            |
>   | ------- | ---- | ----- | ----- | ----- | ------------ |
>   | nums    | 1    | 5     | 2     | 1     | 2            |
>   | dp      | 1    | 5     | 5     | 6     | <u>7</u>     |
>   | isFirst | true | false | false | false | <u>false</u> |

- **Sample code 1**

```c++
class Solution {
public:
    int rob(vector<int>& nums) {  
        int len = nums.size();        
        if (0 == len) return 0;
        if (1 == len) return nums.front();
        if (2 == len) return max(nums.at(0), nums.at(1));
        
        vector<int> dp(len);
        vector<bool> isFirst(len, true);
        
        dp.at(0) = nums.at(0);
        dp.at(1) = max(nums.at(1), nums.at(0));
        isFirst.at(0) = true;
        isFirst.at(1) = nums.at(1) < nums.at(0);
        
        // [1,2,3,1]       
        for (size_t i = 2; i < len - 1; i++)
        { 
            if (dp.at(i-1) < dp.at(i-2) + nums.at(i))
            {
                dp.at(i) = dp.at(i-2) + nums.at(i);
                isFirst.at(i) = isFirst.at(i-2);
            }
            else
            {
                dp.at(i) = dp.at(i-1);
                isFirst.at(i) = isFirst.at(i-1);
            }
        }
        
        if (isFirst.at(len-1-2))
        {
            dp.at(len-1) = dp.at(len-1-1);
             
        }
       	else
       	{
           dp.at(len-1) = max(dp.at(len-1-1), dp.at(len-1-2)+nums.at(len-1));
       	}
        
        return dp.back();
    }
};
```

**Space optimize**

>   Suppose there are `n` houses, since house `0` and `n - 1` are now neighbors, we cannot rob them together and thus the solution is now the maximum of 
>
>   1.  Rob houses `0` to `n - 2`;
>   2.  Rob houses `1` to `n - 1`.

-   **Sample code 2**

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums.front() : 0;
        return max(robber(nums.data(), 0, n - 2), robber(nums.data(), 1, n - 1));
    }
private:
    int robber(const int * nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
```

