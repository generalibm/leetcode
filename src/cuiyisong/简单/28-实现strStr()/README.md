[[28 实现strStr()]](https://leetcode-cn.com/problems/implement-strstr/)

问题：

> 实现 [strStr()](https://baike.baidu.com/item/strstr/811469) 函数。
>
> 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  **-1**。
>
> 示例 1:
>
> ```
> 输入: haystack = "hello", needle = "ll"
> 输出: 2
> ```
>
> 示例 2:
>
> ```
> 输入: haystack = "aaaaa", needle = "bba"
> 输出: -1
> ```
>
> 说明:
>
> 当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
>
> 对于本题而言，当 `needle` 是空字符串时我们应当返回 0 。这与C语言的 [strstr()](https://baike.baidu.com/item/strstr/811469) 以及 Java的 [indexOf()](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)) 定义相符。

解析：

> 1、一种采用比较笨的方法，设定三个 flag 分别指向两个字符串以及当前所在位置。然后依次对比之后的单词，如果都相同则返回当前位置。
>
> 2、采用python中的切片方法，遍历到相同的首字符后采用切片方式对比字符串，若字符串相同直接返回，否则继续向后对比。

解决方案：

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        '''
        if '' == needle:
            return 0
        elif (0 == len(haystack)) or (len(haystack) < len(needle)):
            return -1
        else:
            i, j, k = 0, 0, 0
            while (i < len(haystack)):
                if haystack[i] == needle[k]:
                    i += 1
                    k += 1
                    if k == len(needle):
                        return j
                else:
                    i = j + 1
                    j = i
                    k = 0
            return -1
        '''
        if '' == needle:
            return 0
        else:
            for i in range(0, len(haystack)):
                if i + len(needle) > len(haystack):
                    return -1
                else:
                    if haystack[i : (i + len(needle))] == needle:
                        return i
            return -1
```

