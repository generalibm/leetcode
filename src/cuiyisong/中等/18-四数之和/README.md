[[18 四数之和]](https://leetcode-cn.com/problems/4sum/)

问题：

> 给定一个包含 *n* 个整数的数组 `nums` 和一个目标值 `target`，判断 `nums` 中是否存在四个元素 *a，**b，c* 和 *d* ，使得 *a* + *b* + *c* + *d* 的值与 `target` 相等？找出所有满足条件且不重复的四元组。
>
> **注意：**
>
> 答案中不可以包含重复的四元组。
>
> **示例：**
>
> ```
> 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
> 
> 满足要求的四元组集合为：
> [
>   [-1,  0, 0, 1],
>   [-2, -1, 1, 2],
>   [-2,  0, 0, 2]
> ]
> ```



解析：

> 1、夹逼渐进法。
>
> 2、for 循环暴力判断。



解决方案：

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        tmp_len = len(nums)
        res = []
        for i in range(tmp_len - 3):
            for j in range(i + 1, tmp_len - 2):
                start = j + 1
                end = tmp_len - 1
                while start < end:
                    tmp_res = nums[i] + nums[j] + nums[start] + nums[end]
                    if tmp_res == target:
                        if [nums[i], nums[j], nums[start], nums[end]] not in res:
                            res.append([nums[i], nums[j], nums[start], nums[end]])
                            start += 1
                            end -= 1
                        else:
                            start += 1
                            end -= 1
                    elif tmp_res > target:
                        end -= 1
                    elif tmp_res < target:
                        start += 1
        return res
```

