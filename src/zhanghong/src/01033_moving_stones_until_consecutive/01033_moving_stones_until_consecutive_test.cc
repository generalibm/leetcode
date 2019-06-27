#include "gtest/gtest.h"

#include <vector>

using namespace std;

namespace SolutionTest01033 {

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> s = { a, b, c };
        sort(begin(s), end(s));
        if (s[2] - s[0] == 2)  return {   0, 0};
        return {min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2};
    }
};

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(1, sol.numMovesStones(1, 2, 5).front());
    EXPECT_EQ(2, sol.numMovesStones(1, 2, 5).back());
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(0, sol.numMovesStones(4, 3, 2).front());
    EXPECT_EQ(0, sol.numMovesStones(4, 3, 2).back());
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ(1, sol.numMovesStones(3, 5, 1).front());
    EXPECT_EQ(2, sol.numMovesStones(3, 5, 1).back());
}

TEST_F(SolutionTest, WrongAnswer1)
{
    EXPECT_EQ(1, sol.numMovesStones(1, 2, 6).front());
    EXPECT_EQ(3, sol.numMovesStones(1, 2, 6).back());
}

}// namespace SolutionTest01033




