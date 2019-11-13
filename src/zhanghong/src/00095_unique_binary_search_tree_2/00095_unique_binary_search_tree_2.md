## 95. Unique Binary Search Trees II[Medium]

Given an integer *n*, generate all structurally unique **BST's** (binary search trees) that store values 1 ... *n*.

**Example:**

```
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```



### Solution Analysis

**Recursive solution**

from [leetcode](https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31494/A-simple-recursive-solution) @jayanta, "I start by noting that 1...n is the in-order traversal for any BST with nodes 1 to n. So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1), and the right subtree will contain elements (i+1) to n. I use recursive calls to get back all possible trees for left and right subtrees and combine them in all possible ways with the root."

-   Time: O(n^3)

-   Space: O(n) + dynamic calls stacks

-   Result: AC

-   Code:

```c++
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (0 == n) return vector<TreeNode*>();
        return genTrees(1, n);
    }
    
    vector<TreeNode*> genTrees(int start, int end)
    {
        vector<TreeNode*> res;
        if (start > end)
        {
            res.push_back(nullptr);
            return res;
        }
        vector<TreeNode*> left, right;
        for (int i = start; i <= end; i++)
        {
            left = genTrees(start, i-1);
            right = genTrees(i+1, end);
            for (auto lnode : left)
                for (auto rnode : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
        } 
        return res;
    }    
};
```



