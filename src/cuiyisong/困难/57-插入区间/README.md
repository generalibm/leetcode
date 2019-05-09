[[57 插入区间]](https://leetcode-cn.com/problems/insert-interval/submissions/)

问题：

> 给出一个*无重叠的 ，*按照区间起始端点排序的区间列表。
>
> 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
>
> **示例 1:**
>
> ```
> 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
> 输出: [[1,5],[6,9]]
> ```
>
> **示例 2:**
>
> ```
> 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
> 输出: [[1,2],[3,10],[12,16]]
> 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
> ```



解析：

> 1、数的大小对比。
>
> 2、list 的操作。
>
> 3、逻辑。



解决方案：

```python
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        tmp_start = newInterval[0]
        tmp_end = newInterval[1]
        for i in intervals:
            if tmp_end < i[0] or tmp_start > i[1]:
                res.append(i)
            else:
                if tmp_end >= i[1]:
                    if tmp_start >= i[0]:
                        tmp_start = i[0]
                else:
                    tmp_end = i[1]
                    if tmp_start >= i[0]:
                        tmp_start = i[0]
        res.append([tmp_start, tmp_end])
        res.sort()
        return res
```

