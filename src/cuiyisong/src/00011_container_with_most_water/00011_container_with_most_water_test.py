import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00011_container_with_most_water')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.maxArea([1,8,6,2,5,4,8,3,7]), 49)
    def test_2(self):
        self.assertEqual(self.obj.maxArea([1,0,1]), 2)
    def test_3(self):
        self.assertEqual(self.obj.maxArea([0,1,0]), 0)

if __name__ == '__main__':
    unittest.main()