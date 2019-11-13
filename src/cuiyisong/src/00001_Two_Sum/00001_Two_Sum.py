class Solution:
    def twoSum(self, nums, target):
        d = {}
        for index, num in enumerate(nums):
            tmp = target - num
            if tmp in d:
                return [d[tmp], index]
            d[num] = index
        return None