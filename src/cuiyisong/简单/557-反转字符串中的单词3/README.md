[[557 反转字符串中的单词3]](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)

问题：

> 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
>
> **示例 1:**
>
> ```
> 输入: "Let's take LeetCode contest"
> 输出: "s'teL ekat edoCteeL tsetnoc" 
> ```
>
> **注意：**在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。



解析：

> 1、根据空格进行分隔，然后每个小段进行反转，再拼接返回。
>
> 2、将整个字符串反转，再根据空格分隔拼接。



解决方案：

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        tmp_list = s.split(' ')
        res = ''
        for i in tmp_list:
            res += i[::-1] + ' '
        return res[:-1]
```

