[[342 4的幂]](https://leetcode-cn.com/problems/power-of-four/)

问题：

> 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
>
> **示例 1:**
>
> ```
> 输入: 16
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: 5
> 输出: false
> ```
>
> **进阶：**
> 你能不使用循环或者递归来完成本题吗？



解析：

> 1、同 3 的幂 解法一样。
>
> 2、理论上数字4幂的二进制类似于100，10000，1000000，etc...形式。可以有如下结论：
>
> 1. 4的幂一定是2的。
> 2. 4的幂和2的幂一样，只会出现一位1。但是，4的1总是出现在奇数位。
> 3. `0x5 = 0101b`可以用来校验奇数位上的1。
>
> 那么，
>
> ```dart
> //0x5 = 0101b
> bool isPowerOfFour(int num) {
>     if (num < 0 || num & (num-1)){//check(is or not) a power of 2.
>         return false;
>     }
>     return num & 0x55555555;//check 1 on odd bits
> }
> ```



解决方案：

```python
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        tmp_num = 1
        while tmp_num <= num:
            if tmp_num == num:
                return True
            tmp_num *= 4
        return False
```

