给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。  

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。  

示例 1:  
    给定数组 nums = [1,1,2],  
    函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。  
    你不需要考虑数组中超出新长度后面的元素。  

示例 2:  
    给定 nums = [0,0,1,1,1,2,2,3,3,4],  
    函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。  
    你不需要考虑数组中超出新长度后面的元素。  



解析：  

1、有两种遍历方法，从前向后和从后向前。  

2、从前向后需要考虑删除元素会修改数组长度，导致 out of range 错误  

3、从后向前可以对数组进行删除，即使改变了数组的元素数量也不会导致错误，但是要考虑从后向前的起点和终点。  



class Solution:  
    def removeDuplicates(self, nums: List[int]) -> int:  
        if 0 == len(nums):  
            return 0  
        else:  
            '''从前向后  
            s = 1  
            tmpNum = nums[0]  
            for i in range(0, len(nums)):  
                if nums[i] == tmpNum:  
                    continue  
                else:  
                    nums[s] = nums[i]  
                    tmpNum = nums[i]  
                    s += 1  
            return s  
            '''  
            tmpNum = nums[-1]  
            for i in range(len(nums) - 2, -1, -1):  
                if nums[i] == tmpNum:  
                    nums.remove(nums[i])  
                else:  
                    tmpNum = nums[i]  
            return len(nums)