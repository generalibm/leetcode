import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00055_Jump_Game')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.canJump([2,3,1,1,4]), True)
    def test_2(self):
        self.assertEqual(self.obj.canJump([1,0,1]), False)

if __name__ == '__main__':
    unittest.main()