[[121 买卖股票的最佳时机]](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

问题：

> 给定一个数组，它的第 *i* 个元素是一支给定股票第 *i* 天的价格。
>
> 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
>
> 注意你不能在买入股票前卖出股票。
>
> 示例 1:
>
> ```
> 输入: [7,1,5,3,6,4]
> 输出: 5
> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
>      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
> ```
>
> 示例 2:
>
> ```
> 输入: [7,6,4,3,1]
> 输出: 0
> 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
> ```



解析：

1、最简单的方法，两个中间值，用 for 循环 遍历数组，并两两相减，最后返回相减后的最大值。可以对两个中间值大小进行对比，也可以每次都相减然后将结果与当前最大值进行对比。



```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if [] == prices:
            return 0
        tmpMin = prices[0]
        tmpMax = prices[0]
        tmpRes = 0
        resList = []
        for i in prices:
            if i < tmpMin:
                tmpMin = i
                tmpMax = i
                continue
            elif i > tmpMax:
                tmpMax = i
            tmpRes = tmpMax - tmpMin
            resList.append(tmpRes)
        return sorted(resList)[-1]
```

