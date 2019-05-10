[[58 最后一个单词的长度]](https://leetcode-cn.com/problems/length-of-last-word/)

问题：

> 给定一个仅包含大小写字母和空格 `' '` 的字符串，返回其最后一个单词的长度。
>
> 如果不存在最后一个单词，请返回 0 。
>
> **说明：**一个单词是指由字母组成，但不包含任何空格的字符串。
>
> 示例:
>
> ```
> 输入: "Hello World"
> 输出: 5
> ```

解析：

> 1、由python的split将字符串通过 ' ' 进行分隔，分隔后结果为 list ，取出最后一个非空元素即可。

解决方案：

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        if ' ' not in s and 0 == len(s):
            return 0
        elif ' ' not in s and 0 != len(s):
            return len(s)
        else:
            tmpList = s.split(' ')
            if 0 == len(tmpList):
                return 0
            else:
                for i in range(len(tmpList) - 1, -1, -1):
                    if 0 != len(tmpList[i]):
                        return len(tmpList[i])
                return 0
```

