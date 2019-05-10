[[101 对称二叉树]](https://leetcode-cn.com/problems/symmetric-tree/)

问题：

> 给定一个二叉树，检查它是否是镜像对称的。
>
> 例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。
>
> ```
>     1
>    / \
>   2   2
>  / \ / \
> 3  4 4  3
> ```
>
> 但是下面这个 `[1,2,2,null,3,null,3]` 则不是镜像对称的:
>
> ```
>     1
>    / \
>   2   2
>    \   \
>    3    3
> ```
>
> **说明:**
>
> 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

解析：

> 1、比较简单的方法是用递归的方法，当检测到两边不同的时候就返回 False。
>
> 2、采用迭代的方法，但是不太容易理解。使用队列进行迭代。

解决方案：

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        else:
            return self.isSame(root.left, root.right)
    def isSame(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        elif p == None or q == None:
            return False
        elif p != None and q != None:
            if p.val != q.val:
                return False
            else:
                return self.isSame(p.left, q.right) and self.isSame(p.right, q.left)
```

