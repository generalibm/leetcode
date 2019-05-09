[[367 有效的完全平方数]](https://leetcode-cn.com/problems/valid-perfect-square/)

问题：

> 给定一个正整数 *num*，编写一个函数，如果 *num* 是一个完全平方数，则返回 True，否则返回 False。
>
> **说明：**不要使用任何内置的库函数，如  `sqrt`。
>
> **示例 1：**
>
> ```
> 输入：16
> 输出：True
> ```
>
> **示例 2：**
>
> ```
> 输入：14
> 输出：False
> ```



解析：

> 1、利用 1+3+5+7+9+…+(2n-1)=n^2，即完全平方数肯定是前n个连续奇数的和。（来自 leetcode 评论）
>
> 2、for 循环，然后将数进行平方，判断等一或大于 num。



解决方案：

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        tmp_num = 1
        tmp = 1
        while tmp_num <= num:
            if tmp_num == num:
                return True
            tmp += 2
            tmp_num += tmp
        return False
```

