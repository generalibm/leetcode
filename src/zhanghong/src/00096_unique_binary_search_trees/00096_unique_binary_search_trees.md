## 96. Unique Binary Search Trees[Medium]

> Given *n*, how many structurally unique **BST's** (binary search trees) that store values 1 ... *n*?

**Example:**

```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

### Solution Analysis
> For the first view of the example above, it reminds me the Catalan number(`f(n) = C(2n, n)/(n+1)`) in Mathematics.

**Math approach**

- Time: O(n)
- Space: O(1)
- Result: AC
- Code Sample
```c++
class Solution {
public:
    int numTrees(int n) {
        return catalan(n);
    }
    
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        if (k > n - k) k = n - k;
        
        for (int i = 0; i < k; i++)
        {
            res *= (n-i);
            res /= (i+1);
        }
        
        return res;
    }
    
    int catalan(int n)
    {
        return binomialCoeff(2*n, n)/(n+1);
    }
};
```