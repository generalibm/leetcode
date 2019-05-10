[[35 搜索插入位置]](https://leetcode-cn.com/problems/search-insert-position/)

问题：

> 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
>
> 你可以假设数组中无重复元素。
>
> 示例 1:
>
> ```
> 输入: [1,3,5,6], 5
> 输出: 2
> ```
>
> 示例 2:
>
> ```
> 输入: [1,3,5,6], 2
> 输出: 1
> ```
>
> 示例 3:
>
> ```
> 输入: [1,3,5,6], 7
> 输出: 4
> ```
>
> 示例 4:
>
> ```
> 输入: [1,3,5,6], 0
> 输出: 0
> ```
>
> 

解析：

> 1、直接采用 for 循环查找数组中是否存在大于等于 target 的值。

解决方案：

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if 0 == len(nums):
            return 0
        else:
            for i in range(0, len(nums)):
                if nums[i] >= target:
                    return i
                elif nums[i] < target:
                    pass
            return len(nums)
```

