## 72. Edit Distance[Hard]

> Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

> You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

**Example 1:**

- Input: `word1 = "horse"`, `word2 = "ros"`
- Output: `3`
- Explanation: 
```bash
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')
```

**Example 2:**

- Input: `word1 = "intention"`, `word2 = "execution"`
- Output: `5`
- Explanation: 
```bash
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')
```

### Solution Analysis

**Dynamic Programming Approach**

>   We define the state `dp[i][j]` to be the minimum number of operations to convert `word1[0..i)` to `word2[0..j)`; For the base case, that is, to convert a string to an empty string, the minimum number of operations (deletions) is just the length of the string. So we have `dp[i][0] = i` and `dp[0][j] = j`.
>
>   So, we could get `dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1`.