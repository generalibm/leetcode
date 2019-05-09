[[541 反转字符串2]](https://leetcode-cn.com/problems/reverse-string-ii/)

问题：

> 给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
>
> **示例:**
>
> ```
> 输入: s = "abcdefg", k = 2
> 输出: "bacdfeg"
> ```
>
> **要求:**
>
> 1. 该字符串只包含小写的英文字母。
> 2. 给定字符串的长度和 k 在[1, 10000]范围内。



解析：

> 1、题意为将 k 个字符反转，然后 k 个不反转。
>
> 2、设定两个指针，对合适的字符串进行反转。
>
> 3、将字符串 k 个一组切割，然后将符合题意的字符串反转后拼接返回。



解决方案:

```python
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        if k >= len(s):
            return s[::-1]
        res = ''
        start = 0
        end = k
        while end <= len(s):
            res = res + s[start:end][::-1] + s[start+k:end+k]
            start += 2*k
            end += 2*k
        return (res if end - k == len(s) else res + s[end - k:len(s)][::-1])
```

