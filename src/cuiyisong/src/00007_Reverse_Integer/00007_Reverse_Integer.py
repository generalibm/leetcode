class Solution:
    def reverse(self, x):
        if x >= 0:
            res = int(str(x)[::-1])
            if -2 ** 31 <= res <= 2 ** 31 - 1:
                return res
            else:
                return 0
        elif x < 0:
            res = -int(str(-x)[::-1])
            if -2 ** 31 <= res <= 2 ** 31 - 1:
                return res
            else:
                return 0