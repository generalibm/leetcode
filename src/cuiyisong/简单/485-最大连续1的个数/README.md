[[485 最大连续1的个数]](https://leetcode-cn.com/problems/max-consecutive-ones/)

问题：

> 给定一个二进制数组， 计算其中最大连续1的个数。
>
> **示例 1:**
>
> ```
> 输入: [1,1,0,1,1,1]
> 输出: 3
> 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
> ```
>
> **注意：**
>
> - 输入的数组只包含 `0` 和`1`。
> - 输入数组的长度是正整数，且不超过 10,000。



解析：

> 1、for 循环遍历，并进行计数。
>
> 2、编程字符串，然后通过 0 取分隔，返回最长的串的长度。



解决方案：

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = 0
        res = 0
        for i in nums:
            if i == 1:
                count += 1
                if count > res:
                    res = count
            elif i == 0:
                if count > res:
                    res = count
                count = 0
        return res
```

