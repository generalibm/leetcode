[[680 验证回文字符串]](https://leetcode-cn.com/problems/valid-palindrome-ii/)

问题：

> 给定一个非空字符串 `s`，**最多**删除一个字符。判断是否能成为回文字符串。
>
> **示例 1:**
>
> ```
> 输入: "aba"
> 输出: True
> ```
>
> **示例 2:**
>
> ```
> 输入: "abca"
> 输出: True
> 解释: 你可以删除c字符。
> ```
>
> **注意:**
>
> 1. 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。



解析：

> 1、没什么好说的，我抄的。。。
>
> 2、做不出来，需要判断的条件太多了。
>
> 3、需要判断是否删除一个就可以，是否可以不删除。
>
> 4、我采用的夹逼判断法，但是到最后需要判断是否两个指针相遇，相遇时是已经删除一个还是没删除过，还需要判断相遇时的状态。



解决方案：

```python
class Solution:
    def validPalindrome(self, s: str) -> bool:
        '''
        if s == s[::-1]:
            return True
        start = 0
        end = len(s) - 1
        tmp_flag = True
        while start <= end:
            if s[start] == s[end]:
                if start == end or start + 1 == end or start + 2 == end:
                    return True
                start += 1
                end -= 1
            else:
                if start + 1 == end and tmp_flag == True:
                    return True
                elif start + 1 == end and tmp_flag == False:
                    return False
                elif start + 2 == end:
                    if s[start + 1] == s[start] or s[end - 1] == s[end] and tmp_flag == True:
                        return True
                    return False
                start += 1
                if s[start] == s[end] and tmp_flag == True:
                    tmp_flag = False
                    start += 1
                    end -= 1
                    continue
                start -= 1
                end -= 1
                if s[start] == s[end] and tmp_flag == True:
                    tmp_flag = False
                    start += 1
                    end -= 1
                else:
                    return False
        '''
        if s == s[::-1]:
            return True
        l, r = 0, len(s) - 1
        while l < r:
            if s[l] == s[r]:
                l, r = l + 1, r - 1
            else:
                a = s[l + 1 : r + 1]
                b = s[l:r]
                return a == a[::-1] or b==b[::-1]
```

