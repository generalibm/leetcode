[[66 加一]](https://leetcode-cn.com/problems/plus-one/)

> 问题：
>
> 给定一个由**整数**组成的**非空**数组所表示的非负整数，在该数的基础上加一。
>
> 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
>
> 你可以假设除了整数 0 之外，这个整数不会以零开头。
>
> **示例 1:**
>
> ```
> 输入: [1,2,3]
> 输出: [1,2,4]
> 解释: 输入数组表示数字 123。
> ```
>
> **示例 2:**
>
> ```
> 输入: [4,3,2,1]
> 输出: [4,3,2,2]
> 解释: 输入数组表示数字 4321。
> ```



解析：

> 1、题目本身没什么难点，主要是需要考虑边界问题。
>
> 2、要考虑进位，考虑 list 转 int 是否会超出 int 范围等方面。



解决方案：

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            if 9 == digits[i] and 0 != i:
                digits[i] = 0
                continue
            elif 9 == digits[i] and 0 == i:
                digits[i] = 0
                digits.insert(i, 1)
            elif 9 != digits[i]:
                digits[i] += 1
                break
        return digits
```

