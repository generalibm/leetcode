[[771 宝石与石头]](https://leetcode-cn.com/problems/jewels-and-stones/submissions/)

问题：

>  给定字符串`J` 代表石头中宝石的类型，和字符串 `S`代表你拥有的石头。 `S` 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
>
> `J` 中的字母不重复，`J` 和 `S`中的所有字符都是字母。字母区分大小写，因此`"a"`和`"A"`是不同类型的石头。
>
> **示例 1:**
>
> ```
> 输入: J = "aA", S = "aAAbbbb"
> 输出: 3
> ```
>
> **示例 2:**
>
> ```
> 输入: J = "z", S = "ZZ"
> 输出: 0
> ```
>
> **注意:**
>
> - `S` 和 `J` 最多含有50个字母。
> -  `J` 中的字符不重复。



解析：

> 1、简单的字符串是否包含的判断。



解决方案：

```python
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        '''
        #88ms
        return sum(S.count(i) for i in J)
        '''
        '''
        #56ms
        tmp_dict = {}
        for i in S:
            if i in tmp_dict:
                tmp_dict[i] += 1
            else:
                tmp_dict[i] = 1
        res = 0
        for j in J:
            if j in tmp_dict:
                res += tmp_dict[j]
        return res
        '''
        #56ms
        res = 0
        for i in S:
            if i in J:
                res += 1
        return res
```

