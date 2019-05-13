import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00001_Two_Sum')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.twoSum([2,3,1,1,6], 5), [0,1])
    def test_2(self):
        self.assertEqual(self.obj.twoSum([1,0,5,8,2], 1), [0,1])

if __name__ == '__main__':
    unittest.main()