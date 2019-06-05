import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00165_compare_version_numbers')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.compareVersion('1.0.1', '1.1.1'), -1)
    def test_2(self):
        self.assertEqual(self.obj.compareVersion('1.1.1', '1.0.1'), 1)
    def test_3(self):
        self.assertEqual(self.obj.compareVersion('1.1.0', '1.1'), 0)
    def test_4(self):
        self.assertEqual(self.obj.compareVersion('1.0.0', '1.1'), -1)

if __name__ == '__main__':
    unittest.main()