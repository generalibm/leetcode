## Description

Given the `root` of a binary tree, return  *the length of the **diameter** of the tree* .

The **diameter** of a binary tree is the **length** of the longest path between any two nodes in a tree. This path may or may not pass through the `root`.

The **length** of a path between two nodes is represented by the number of edges between them.

### **Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg)

<pre><strong>Input:</strong> root = [1,2,3,4,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is the length of the path [4,2,1,3] or [5,2,1,3].
</pre>

### **Example 2:**

<pre><strong>Input:</strong> root = [1,2]
<strong>Output:</strong> 1
</pre>

**Constraints:**

* The number of nodes in the tree is in the range `[1, 10<sup>4</sup>]`.
* `-100 <= Node.val <= 100`


## Solutions

### C++ version

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }

    int height(TreeNode* x, int& diameter) {
        if (!x)
            return 0;

        int heightL = height(x->left, diameter);
        int heightR = height(x->right, diameter);

        diameter = max(diameter, heightL + heightR);
        // cout << "x = " << x->val << ", heightL = " << heightL << ", heightR =
        // " << heightR << ", diameter = " << diameter << "\n";

        return max(heightL, heightR) + 1;
    }
};
```

### python3 version from c++ version
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = [0]  # Initialize the variable to store the diameter of the binary tree
        self.height(root, ans)  # Calculate the height of the binary tree
        return ans[0]  # Return the diameter

    def height(self, x, diameter):
        if not x:
            return 0

        heightL = self.height(x.left, diameter)  # Calculate the height of the left subtree
        heightR = self.height(x.right, diameter)  # Calculate the height of the right subtree

        diameter[0] = max(diameter[0], heightL + heightR)  # Update the diameter if necessary

        return max(heightL, heightR) + 1  # Return the height of the current node
```

### Python3 version 2, rewrite as inner function
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.max_diameter = 0
        def binary_tree_diameter_recursive(node):
            if not node:
                return 0
            left_height = binary_tree_diameter_recursive(node.left)
            right_height = binary_tree_diameter_recursive(node.right)
            cur_height = max(left_height, right_height) + 1
            cur_length = left_height + right_height
            if cur_length > self.max_diameter:
                self.max_diameter = cur_length
            return cur_height
        binary_tree_diameter_recursive(root)
        return self.max_diameter
```

### Python3 version 3, rewrite as two return values
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        _, max_dia = self.__diameterOfBinaryTree(root)
        return max_dia
    

    def __diameterOfBinaryTree(self, root: Optional[TreeNode]):
        if not root: return 0, 0

        left_max_depth, left_max_dia = self.__diameterOfBinaryTree(root.left)
        right_max_depth, right_max_dia = self.__diameterOfBinaryTree(root.right)

        depth = max(left_max_depth, right_max_depth) + 1
        max_dia = max(left_max_depth + right_max_depth, left_max_dia, right_max_dia)
        return depth, max_dia        
```

### Rust version
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut ans = vec![0]; // Initialize the variable to store the diameter of the binary tree
        Solution::height(root, &mut ans); // Calculate the height of the binary tree
        ans[0] // Return the diameter
    }

    // Recursive function to calculate the height of the binary tree
    fn height(node: Option<Rc<RefCell<TreeNode>>>, diameter: &mut Vec<i32>) -> i32 {
        if let Some(n) = node {
            // Clone the Rc references before making recursive calls to ensure that each function call has its own reference
            let n = n.borrow();
            
            let height_l = Solution::height(n.left.clone(), diameter); // Calculate the height of the left subtree
            let height_r = Solution::height(n.right.clone(), diameter); // Calculate the height of the right subtree

            diameter[0] = i32::max(diameter[0], height_l + height_r); // Update the diameter if necessary

            i32::max(height_l, height_r) + 1 // Return the height of the current node
        } else {
            0 // Return 0 if the node is None
        }
    }
}
```

### Rust version with the inner function
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cmp;
use std::cell::RefCell;
impl Solution {
    pub fn diameter_of_binary_tree(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn traverse(root: Option<Rc<RefCell<TreeNode>>>, mut max: &mut i32) -> i32 {
            if let Some(n) = root {
                let nb = n.borrow();
                let left_h = traverse(nb.left.clone(), max);
                let right_h = traverse(nb.right.clone(), max);
                *max = cmp::max(*max, left_h + right_h);
                cmp::max(left_h, right_h) + 1
            } else {
                0
            }
        }
        let mut max = 0;
        traverse(root, &mut max);
        max
    }
}
```