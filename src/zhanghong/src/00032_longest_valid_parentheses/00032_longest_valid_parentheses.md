## 32. Longest Valid Parentheses[Hard]

> Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**

- Input: "(()"
- Output: 2
- Explanation: The longest valid parentheses substring is "()"

**Example 2:**

- Input: ")()())"
- Output: 4
- Explanation: The longest valid parentheses substring is "()()"

### Solution Analysis

**Brute-force Approach**
> We all know that `()` or `()()` , `()()()...` could be easily counted. So the idea is to count all the substring's valid length. 

- Time: O(n^3)
- Space: O(n)
- Result: TLE

**Brute-force Optimization Approach**
> When we use *stack* for help, we would not need to check all substrings, since the indices tell us the 