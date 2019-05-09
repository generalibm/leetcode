[[518 最短无序连续子数组]](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)

问题：

> 给定一个整数数组，你需要寻找一个**连续的子数组**，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
>
> 你找到的子数组应是**最短**的，请输出它的长度。
>
> **示例 1:**
>
> ```
> 输入: [2, 6, 4, 8, 10, 9, 15]
> 输出: 5
> 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
> ```
>
> **说明 :**
>
> 1. 输入的数组长度范围在 [1, 10,000]。
> 2. 输入的数组可能包含**重复**元素 ，所以**升序**的意思是**<=。**



解析：

> 1、去掉头部的最小值，去掉尾部的最大值，就是需要排序的数组。
>
> 2、最小值和最大值通过排序后数组与排序前数组对比获得。



解决方案：

```python
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        res_list = sorted(nums)
        if res_list == nums:
            return 0
        start = 0
        end = 0
        for i in range(0, len(res_list)):
            if res_list[i] != nums[i]:
                start = i
                break
        for j in range(len(res_list)-1, start, -1):
            if res_list[j] != nums[j]:
                end = j
                break
        return end - start + 1
```

