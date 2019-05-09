[[169 求众数]](https://leetcode-cn.com/problems/majority-element/)

问题：

> 给定一个大小为 *n* 的数组，找到其中的众数。众数是指在数组中出现次数**大于** `⌊ n/2 ⌋` 的元素。
>
> 你可以假设数组是非空的，并且给定的数组总是存在众数。
>
> **示例 1:**
>
> ```
> 输入: [3,2,3]
> 输出: 3
> ```
>
> **示例 2:**
>
> ```
> 输入: [2,2,1,1,1,2,2]
> 输出: 2
> ```



解析：

> 1、数量大于总数的一半，也就是说排序后这个数肯定在会在中间出现。



解决方案：

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # 64ms 14.6mb
        nums = sorted(nums)
        return nums[int(len(nums) / 2)]
        '''
        # 120ms 14.1mb
        tmp_dict = {}
        for i in nums:
            if i in tmp_dict:
                tmp_dict[i] += 1
            else:
                tmp_dict[i] = 1
        n = 0
        tmp_count = 0
        for j in tmp_dict:
            if tmp_count >= tmp_dict[j]:
                continue
            else:
                tmp_count = tmp_dict[j]
                n = j
        return n
        '''
        '''
        # 96ms 14.4mb
        nums = sorted(nums)
        return nums[(len(nums) // 2)]
        '''
```

