[[551 学生出勤记录]](https://leetcode-cn.com/problems/student-attendance-record-i/)

问题：

> 给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：
>
> 1. **'A'** : Absent，缺勤
> 2. **'L'** : Late，迟到
> 3. **'P'** : Present，到场
>
> 如果一个学生的出勤记录中不**超过一个'A'(缺勤)**并且**不超过两个连续的'L'(迟到)**,那么这个学生会被奖赏。
>
> 你需要根据这个学生的出勤记录判断他是否会被奖赏。
>
> **示例 1:**
>
> ```
> 输入: "PPALLP"
> 输出: True
> ```
>
> **示例 2:**
>
> ```
> 输入: "PPALLL"
> 输出: False
> ```



解析：

> 1、暴力计数法。
>
> 2、字符串匹配，查看字符串中是否有 A 和 LLL 这种字符。



解决方案：

```python
class Solution:
    def checkRecord(self, s: str) -> bool:
        '''
        count_a = 0
        count_l = 0
        for i in s:
            if i == 'A':
                count_a += 1
                if count_a > 1:
                    return False
                count_l = 0
            elif i == 'L':
                count_l += 1
                if count_l > 2:
                    return False
            else:
                count_l = 0
        return True
        '''
        if s.count('A') <= 1 and "LLL" not in s:
            return True
        return False
```

