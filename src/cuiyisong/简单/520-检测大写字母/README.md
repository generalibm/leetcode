[[520 检测大写字母]](https://leetcode-cn.com/problems/detect-capital/)

问题：

> 给定一个单词，你需要判断单词的大写使用是否正确。
>
> 我们定义，在以下情况时，单词的大写用法是正确的：
>
> 1. 全部字母都是大写，比如"USA"。
> 2. 单词中所有字母都不是大写，比如"leetcode"。
> 3. 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
>
> 否则，我们定义这个单词没有正确使用大写字母。
>
> **示例 1:**
>
> ```
> 输入: "USA"
> 输出: True
> ```
>
> **示例 2:**
>
> ```
> 输入: "FlaG"
> 输出: False
> ```
>
> **注意:** 输入是由大写和小写拉丁字母组成的非空单词。



解析：

> 1、使用 python 自带的检测方法。
>
> 2、for 循环判断第一个字母和其他字母是否符合要求。



解决方案：

```python
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return word.islower() or word.isupper() or word.istitle()
```

