import unittest

#Solution = __import__('Solution', fromlist = '00011_container_with_most_water')
Solution = __import__('00007_Reverse_Integer')

class demoTest(unittest.TestCase):
    obj = Solution.Solution()
    def test_1(self):
        self.assertEqual(self.obj.reverse(123), 321)
    def test_2(self):
        self.assertEqual(self.obj.reverse(-123), -321)
    def test_3(self):
        self.assertEqual(self.obj.reverse(120), 21)
    def test_4(self):
        self.assertEqual(self.obj.reverse(1000000), 1)

if __name__ == '__main__':
    unittest.main()