[[217 存在重复元素]](https://leetcode-cn.com/problems/contains-duplicate/)

问题：

> 给定一个整数数组，判断是否存在重复元素。
>
> 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
>
> **示例 1:**
>
> ```
> 输入: [1,2,3,1]
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: [1,2,3,4]
> 输出: false
> ```
>
> **示例 3:**
>
> ```
> 输入: [1,1,1,3,3,4,3,2,4,2]
> 输出: true
> ```



解析：

> 1、可以采用 for 循环的方法，对数字进行判断，耗时长。
>
> 2、采用 python 特有的 set 没有重复元素的特性，将 list 转为 set，并对比大小。



解决方案：

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)
```

