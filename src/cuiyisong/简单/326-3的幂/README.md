[[326 3的幂]](https://leetcode-cn.com/problems/power-of-three/)

问题：

> 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
>
> **示例 1:**
>
> ```
> 输入: 27
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: 0
> 输出: false
> ```
>
> **示例 3:**
>
> ```
> 输入: 9
> 输出: true
> ```
>
> **示例 4:**
>
> ```
> 输入: 45
> 输出: false
> ```
>
> **进阶：**
> 你能不使用循环或者递归来完成本题吗？



解析：

> 1、将这个数一直除 3，直到不能除，判断是否为 0.
>
> 2、反过来将一个属乘 3，直到与这个数相等或大于这个数。



解决方案：

```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        tmp_num = 1
        while tmp_num <= n:
            if tmp_num == n:
                return True
            tmp_num *= 3
        return False
```

