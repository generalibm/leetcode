## 5. Longest Palindromic Substring[Medium]

>Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

**Example 1:**

- Input: "babad"
- Output: "bab"
- Note: "aba" is also a valid answer.

**Example 2:**

- Input: "cbbd"
- Output: "bb"

### Solution Analysis

#### Approach 1

**Brute-force Solution:**

> brute-force with O(n^3)--O(n^2) pairs and O(n) for checking palindrome.

```c++
string longestPalindrome(const string & rhs)
    {
        /// "babad"
        int idx = 0, idy = 0;
        int len = 0;

        for (int i = 0; i < rhs.size(); i++)
        {
            for (int j = 0; j < rhs.size(); j++)
            {
                if (isPalindromic(rhs.substr(i, j - i + 1)))
                {
                    if (len < (j - i + 1))
                    {
                        len = j - i + 1;
                        idx = i;
                        idy = j;
                    }

                }
            }
        }

        return rhs.substr(idx, idy-idx+1);
    }

    bool isPalindromic(const string & rhs)
    {
        for (int i = 0, j = rhs.size() - 1; i <= j; i++, j--)
        {
            if (rhs[i] != rhs[j]) return false;
        }
        return true;
    }
```
> BUT, it will just pass 59/103 test cases.

**Decrease complexity**

> Since the checking costs O(n) time, we can reduce it to O(1) by reusing some previous computation.

#### Approach 2
**Expand Around Center**

> In fact, we could solve it in `O(n^2)` time using only constant space.
> We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only `2n−1` such centers.
> You might be asking why there are `2n−1` but not `n` centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.

```c++
string longestPalindrome(const string & s) {
    if (s.empty() || s.size() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = std::max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start, end + 1);
}

int expandAroundCenter(const string & s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.size() && s.at(L) == s.at(R)) {
        L--;
        R++;
    }
    return R - L - 1;
}
```

### Approach 3

**Manacher Algorithm**