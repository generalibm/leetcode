[[796 旋转字符串]](https://leetcode-cn.com/problems/rotate-string/)

问题：

> 给定两个字符串, `A` 和 `B`。
>
> `A` 的旋转操作就是将 `A` 最左边的字符移动到最右边。 例如, 若 `A = 'abcde'`，在移动一次之后结果就是`'bcdea'` 。如果在若干次旋转操作之后，`A` 能变成`B`，那么返回`True`。
>
> ```
> 示例 1:
> 输入: A = 'abcde', B = 'cdeab'
> 输出: true
> 
> 示例 2:
> 输入: A = 'abcde', B = 'abced'
> 输出: false
> ```
>
> **注意：**
>
> - `A` 和 `B` 长度不超过 `100`。



解析：

> 1、字符串匹配。
>
> 2、字符走起来。



解决方案：

```python
class Solution:
    def rotateString(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if len(A) == 0:
            return True
        start = A[0]
        tmp_index = 0
        while True:
            tmp_index = B.find(start, tmp_index + 1)
            if tmp_index == -1:
                return False
            if B[0:tmp_index] == A[len(A)-tmp_index:] and B[tmp_index:] == A[0:len(A)-tmp_index]:
                return True
        return False
```

