### 152. Maximum Product Subarray[Medium]

>Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

**Example 1:**

- Input: [2,3,-2,4]
- Output: 6
- Explanation: [2,3] has the largest product 6.

**Example 2:**

- Input: [-2,0,-1]
- Output: 0
- Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

**Solution Analysis**

**Brute force**
- Time: O(n^3)
- Space: O(1)

**Divide Conquer**
- Time: O(n^2)
- Space: O(n)

**Dynamic Programming**
- Time: O(n)
- Space: O(n)

**Prefix Array**
- Time: O(n)
- Space: O(1)
