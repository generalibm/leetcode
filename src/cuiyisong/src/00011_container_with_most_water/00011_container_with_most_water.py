class Solution:    
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res = 0
        start = 0
        end = len(height) - 1
        while start < end:
            tmp_res = (end - start) * (height[start] if height[start] < height[end] else height[end])
            if tmp_res > res:
                res = tmp_res
            if height[start] < height[end]:
                start += 1
            else:
                end -= 1
        return res