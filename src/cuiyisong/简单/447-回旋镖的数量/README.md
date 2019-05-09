[[447 回旋镖的数量]](https://leetcode-cn.com/problems/number-of-boomerangs/)

问题：

> 给定平面上 *n* 对不同的点，“回旋镖” 是由点表示的元组 `(i, j, k)` ，其中 `i` 和 `j` 之间的距离和 `i` 和 `k` 之间的距离相等（**需要考虑元组的顺序**）。
>
> 找到所有回旋镖的数量。你可以假设 *n* 最大为 **500**，所有点的坐标在闭区间 **[-10000, 10000]** 中。
>
> **示例:**
>
> ```
> 输入:
> [[0,0],[1,0],[2,0]]
> 
> 输出:
> 2
> 
> 解释:
> 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
> ```



解析：

> 1、遍历。计算两点之间距离，然后以一个点为圆心，去找所以在半径上的点。



解决方案：

```python
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def quadratic(x1: List[int], x2: List[int])-> int:
            return (x1[0]-x2[0])*(x1[0]-x2[0]) + (x1[1]-x2[1])*(x1[1]-x2[1])
        res = 0
        for i in range(len(points)):
            tmp_dict = {}
            for j in range(len(points)):
                if i == j:
                    continue
                else:
                    tmp_num = quadratic(points[i], points[j])
                    if tmp_num in tmp_dict:
                        tmp_dict[tmp_num].append(j)
                    else:
                        tmp_dict[tmp_num] = [j]
            for k in tmp_dict:
                if len(tmp_dict[k]) >= 2:
                    res += len(tmp_dict[k]) * (len(tmp_dict[k]) - 1)
        return res
```

