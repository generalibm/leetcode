class Solution:
    def findMin(self, nums) -> int:
        '''
        for i in range(1,len(nums)):
            if nums[i] < nums[0]:
                return nums[i]
        return nums[0]
        '''
        left=0
        right=len(nums)-1
        while left<right:
            if nums[left]<=nums[right]:
                break
            mid=(left+right)//2
            if nums[mid]>nums[right]:
                left=mid+1
            else:
                right=mid
        return nums[left]