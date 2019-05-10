[[17 电话号码的字母组合]](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

问题：

> 给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。
>
> 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
>
> ![img](http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)
>
> **示例:**
>
> ```
> 输入："23"
> 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
> ```
>
> **说明:**
> 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。



解析：

> 1、for 循环暴力破解。
>
> 2、暂无。



解决方案：

```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        for s in dict[int(digits[n-1])]:
            ans.append(s)
        n = n-1
        while n>0:
            temp = []
            for i in dict[int(digits[n-1])]:
                for j in ans:
                    temp.append(i+j)
            n = n-1
            ans = temp
        return ans
```

