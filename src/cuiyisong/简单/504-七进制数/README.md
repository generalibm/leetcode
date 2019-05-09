[[504 七进制数]](https://leetcode-cn.com/problems/base-7/)

问题：

> 给定一个整数，将其转化为7进制，并以字符串形式输出。
>
> **示例 1:**
>
> ```
> 输入: 100
> 输出: "202"
> ```
>
> **示例 2:**
>
> ```
> 输入: -7
> 输出: "-10"
> ```
>
> **注意:** 输入范围是 [-1e7, 1e7] 。



解析：

> 1、按照进制除法进行解题。
>
> 2、调用 python 库。



解决方案：

```python
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num < 0:
            num = -num
            res = '-'
        elif num == 0:
            return '0'
        else:
            res = ''
        tmp_res = ''
        while num > 0:
            tmp_res = str(int(num % 7)) + tmp_res
            num = int(num / 7)
        return res + tmp_res
```

