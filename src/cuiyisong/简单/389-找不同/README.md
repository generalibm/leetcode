[[389 找不同]](https://leetcode-cn.com/problems/find-the-difference/)

问题：

> 给定两个字符串 ***s*** 和 ***t***，它们只包含小写字母。
>
> 字符串 **t** 由字符串 **s** 随机重排，然后在随机位置添加一个字母。
>
> 请找出在 ***t*** 中被添加的字母。
>
>  
>
> **示例:**
>
> ```
> 输入：
> s = "abcd"
> t = "abcde"
> 
> 输出：
> e
> 
> 解释：
> 'e' 是那个被添加的字母。
> ```



解析：

> 1、list。
>
> 2、将字符串转为字符数组，求和，两个字符转数组和做差，转回字符。



解决方案：

```python
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        a = 0
        b = 0
        for i in s:
            a += ord(i)
        for j in t:
            b += ord(j)
        return chr(b - a)
```

