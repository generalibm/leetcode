[[500 键盘行]](<https://leetcode-cn.com/problems/keyboard-row/>)

问题：

> 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
>
>  
>
> ![American keyboard](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png)
>
>  
>
> **示例：**
>
> ```
> 输入: ["Hello", "Alaska", "Dad", "Peace"]
> 输出: ["Alaska", "Dad"]
> ```
>
>  
>
> **注意：**
>
> 1. 你可以重复使用键盘上同一字符。
> 2. 你可以假设输入的字符串将只包含字母。



解析：

> 1、直接使用 python 的 set 方法中的比大小。
>
> 2、for 循环，暴力算解。



解决方案：

```python
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        set1 = set('ZXCVBNMzxcvbnm')
        set2 = set('ASDFGHJKLasdfghjkl')
        set3 = set('QWERTYUIOPqwertyuiop')
        
		return [x for x in words if set(x)<=set1 or set(x)<=set2 or set(x)<=set3]
```

