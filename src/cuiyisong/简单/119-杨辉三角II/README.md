[[119 杨辉三角II]](https://leetcode-cn.com/problems/pascals-triangle-ii/)

问题：

> 给定一个非负索引 *k*，其中 *k* ≤ 33，返回杨辉三角的第 *k* 行。
>
> ![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
>
> 在杨辉三角中，每个数是它左上方和右上方的数的和。
>
> 示例:
>
> ```
> 输入: 3
> 输出: [1,3,3,1]
> ```
>
> 进阶：
>
> 你可以优化你的算法到 *O*(*k*) 空间复杂度吗？

解析：

> 1、在杨辉三角的基础上进行了修改，只需要输出一行的 list 即可满足要求。

解决方案：

```python
class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        now = []
        for i in range(rowIndex + 1):
            now = [1]*(i+1)
            if i >= 2:
                for n in range(1,i):
                    now[n] = pre[n-1]+pre[n]
            pre = now
        return now
```