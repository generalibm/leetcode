import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00153_find_minimum_in_rotated_sorted_array')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.findMin([3,4,5,1,2]), 1)
    def test_2(self):
        self.assertEqual(self.obj.findMin([4,5,6,7,0,1,2]), 0)

if __name__ == '__main__':
    unittest.main()