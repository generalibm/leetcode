给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。  

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。  

示例 1:  
    给定 nums = [2, 7, 11, 15], target = 9  
    因为 nums[0] + nums[1] = 2 + 7 = 9  
    所以返回 [0, 1]  

示例 2:  
    给定 nums = [2, 7, 11, 12], target = 14  
    因为 nums[0] + nums[3] = 2 + 12 = 14  
    所以返回 [0, 3]，不能返回 [2, 2]  



解析:  

1、比较笨的方法，从头遍历到尾部，并两个两个去相加，需要双层 for 循环，耗时长，复杂度高。如果恰好数组前两位的和为 target ，这种方法非常快。  

2、将下标和数字写入字典中，以数字为 key ，下标为 value ，通过 for 循环判断 target 减去for循环的数，查看结果是否存在在字典中。  



class Solution:  
    def twoSum(self, nums: List[int], target: int) -> List[int]:  
        d = {}  
        for index, num in enumerate(nums):  
            tmp = target - num  
            if tmp in d:  
                return [d[tmp], index]  
            else:  
                d[num] = index  
        return None  



enumerate:  
    作用是同时返回一串字符串中的字符下标和字符。本例中返回下标和数字。