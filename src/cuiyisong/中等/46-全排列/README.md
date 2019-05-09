[[46 全排列]](https://leetcode-cn.com/problems/permutations/)

问题：

> 给定一个**没有重复**数字的序列，返回其所有可能的全排列。
>
> **示例:**
>
> ```
> 输入: [1,2,3]
> 输出:
> [
>   [1,2,3],
>   [1,3,2],
>   [2,1,3],
>   [2,3,1],
>   [3,1,2],
>   [3,2,1]
> ]
> ```



解析：

> 1、主要采用递归方法。
>
> 2、将问题分成只剩两个数，然后两个数进行排列。
>
> 3、答案半抄半写，算是弄得差不多明白了。



解决方案：

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        if len(nums) == 1:
            return [nums]
        for i in range(0, len(nums)):
            for j in self.permute(nums[0:i] + nums[i+1:]):
                res.append([nums[i]] + j)
        return res
```

