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
> BUT, it will just 59/103 test cases.

