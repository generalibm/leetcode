## 132. Palindrome Partitioning II[Hard]

Given a string *s*, partition *s* such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of *s*.

**Example:**

```bash
Input: "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

### Solution Analysis

-   **Time**: O(n^2)
-   **Space**: O(n^2)
-   **Result**: AC

>   Such solution firstly constructs a two-dimensional bool array `isPalin` to indicate whether the sub-string *s[i:j]* is palindrome, which we need O(n^2) time and space complexity. Then, we need another array `minCuts` to do DP, which `minCuts[i]` keeps the minimum cuts found in the substring *s[0:i-1]*.
>
>   `isPalin[i][j] = isPalin[i+1][j-1] && s[i]==s[j]`
>
>   `minCuts[i] = min{minCut[i-1]+1, minCuts[i]}`

-   **Code Sample**

```c++
class Solution {
    public:
        int minCut(string s) {
            const int N = s.size();
            if(N<=1) return 0;
            int i,j;
            bool isPalin[N][N];
            fill_n(&isPalin[0][0], N*N, false);
            int minCuts[N+1];
            for(i=0; i<=N; ++i) minCuts[i] = i-1;
            
            for(j=1; j<N; ++j)
            {
                for(i=j; i>=0; --i)
                {
                    if( (s[i] == s[j]) && ( ( j-i < 2 ) || isPalin[i+1][j-1] ) )
                    {
                        isPalin[i][j] = true;
                        minCuts[j+1] = min(minCuts[j+1], 1 + minCuts[i]);    
                    }
                }
            }
            return minCuts[N];
        }
    };
```

