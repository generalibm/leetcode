[[100 相同的树]](https://leetcode-cn.com/problems/same-tree/)

问题：

> 给定两个二叉树，编写一个函数来检验它们是否相同。
>
> 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
>
> 示例 1:
>
> ```
> 输入:       1         1
>           / \       / \
>          2   3     2   3
>         [1,2,3],   [1,2,3]
> 输出: true
> ```
>
>
> 示例 2:
>
> ```
> 输入:      1          1
>           /           \
>          2             2
>         [1,2],     [1,null,2]
> 输出: false
> ```
>
>
> 示例 3:
>
> ```
> 输入:       1         1
>           / \       / \
>          2   1     1   2
>         [1,2,1],   [1,1,2]
> 输出: false
> ```

解析：

> 1、在知道数据量比较少的时候，可以采用 for 循环来进行遍历，出现不同即返回 False。
>
> 2、在不知道数据量大小的情况下，采用递归是一个好的解决方案。
>
> 3、也可以采用分别遍历二叉树，将数据放入到 list 中，然后直接判断两个 list 是否相同。

解决方案：

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None and q == None:
            return True
        elif p != None and q != None:
            if p.val == q.val:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            else:
                return False
        else:
            return False
```

