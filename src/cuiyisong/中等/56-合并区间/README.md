[[56 合并区间]](https://leetcode-cn.com/problems/merge-intervals/submissions/)

问题：

> 给出一个区间的集合，请合并所有重叠的区间。
>
> **示例 1:**
>
> ```
> 输入: [[1,3],[2,6],[8,10],[15,18]]
> 输出: [[1,6],[8,10],[15,18]]
> 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
> ```
>
> **示例 2:**
>
> ```
> 输入: [[1,4],[4,5]]
> 输出: [[1,5]]
> 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
> ```



解析：

> 1、通过 for 循环来获取一个区间的后一个数与下一个区间前一个数的大小对比，然后根据结果来将区间合并。



解决方案：

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) < 2:
            return intervals
        intervals.sort()
        tmp_list = [intervals[0]]
        for i in range(1, len(intervals)):
            if tmp_list[-1][1] >= intervals[i][0]:
                if tmp_list[-1][1] < intervals[i][1]:
                    tmp_list[-1][1] = intervals[i][1]
            else:
                tmp_list.append(intervals[i])
        return tmp_list
```

