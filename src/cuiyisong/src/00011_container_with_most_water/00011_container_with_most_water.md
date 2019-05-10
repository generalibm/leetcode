[[11 盛最多水的容器]](https://leetcode-cn.com/problems/container-with-most-water/)

问题：

> 给定 *n* 个非负整数 *a*1，*a*2，...，*a*n，每个数代表坐标中的一个点 (*i*, *ai*) 。在坐标内画 *n* 条垂直线，垂直线 *i* 的两个端点分别为 (*i*, *ai*) 和 (*i*, 0)。找出其中的两条线，使得它们与 *x* 轴共同构成的容器可以容纳最多的水。
>
> **说明：**你不能倾斜容器，且 *n* 的值至少为 2。
>
> ![img](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)
>
> 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
>
>  
>
> **示例:**
>
> ```
> 输入: [1,8,6,2,5,4,8,3,7]
> 输出: 49
> ```



解析：

> 1、从两侧夹逼来进行判断。
>
> 2、找到两侧中比较小的，然后向中间近一步，再进行计算判断。
>
> 3、最后返回最大的结果。



解决方案：

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        res = 0
        start = 0
        end = len(height) - 1
        while start < end:
            tmp_res = (end - start) * (height[start] if height[start] < height[end] else height[end])
            if tmp_res > res:
                res = tmp_res
            if height[start] < height[end]:
                start += 1
            else:
                end -= 1
        return res
```

