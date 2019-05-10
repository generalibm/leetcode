class Solution:
    def canJump(self, nums):
        tmp_num = 1
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] >= tmp_num:
                tmp_num = 1
            else:
                tmp_num += 1
            if i == 0 and tmp_num > 1:
                return False
        return True