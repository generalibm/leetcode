import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00174_dungeon_game')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.calculateMinimumHP([[-2,-3,3],[-5,-10,1],[10,30,-5]]), 7)
    def test_2(self):
        self.assertEqual(self.obj.calculateMinimumHP([[1,2,3],[3,-3,3],[1,4,-7]]), 1)

if __name__ == '__main__':
    unittest.main()