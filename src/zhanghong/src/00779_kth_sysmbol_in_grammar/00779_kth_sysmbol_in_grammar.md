## 779. K-th Symbol in Grammar[Medium]

On the first row, we write a `0`. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

Given row `N` and index `K`, return the `K`-th indexed symbol in row `N`. (The values of `K` are 1-indexed.) (1 indexed).

```
Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
```

**Note:**

1. `N` will be an integer in the range `[1, 30]`.
2. `K` will be an integer in the range `[1, 2^(N-1)]`.



## Solution Analysis

### Approach 1 - Recusion

**Strategy: ** Recursion

**Explanation:**

It is obviously that all the rows and cellums generate a *complete binary tree* in which the node is either `1` or `0`. More specifically, the generation process will come from the following two way:

```json
	0                     1
   / \        or         / \
  0   1                 1   0
  case 1                case 2
```

so, 

​	`f(n, k) = f(n-1, (k+1)/2)`  in case of  k is odd (the left child in the complete binary tree)

​    `f(n, k) = f(n-1, (k+1)/2) xor 1`  in case of k is even(the right child in the complete binary tree)

**Source Code:**

```c++
int kthGrammar(int N, int K) {
	/// base case
    if (N == 1 and K == 1) return 0;
    
	/// left child
    if (K % 2 == 1) return kthGrammar(N-1, (K+1)/2);
    
    /// right child
    return kthGrammar(N-1, (K+1)/2) xor 1;
}
```

**Time Complexity:** O(N)

**Space Complexity:** O(1), but system stack is O(N)

**Result:** AC(0ms)