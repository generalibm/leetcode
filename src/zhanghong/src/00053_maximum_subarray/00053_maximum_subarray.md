## 53. Maximum Subarray[Easy]

>Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

- Input: `[-2,1,-3,4,-1,2,1,-5,4],`
- Output: `6`
- Explanation: `[4,-1,2,1]` has the largest `sum = 6`.

**Follow up:**

>If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**Solution**

- **brute force**
- Time: O(n^2)
- Space: O(1)


- **divide conquer**
- Time: O(n*log(n))
- Space: O(n) + stack consume


- **dynamic programming**
- Time: O(n)
- Space: O(n)


- **prefix array**
- Time: O(n)
- Space: O(1)