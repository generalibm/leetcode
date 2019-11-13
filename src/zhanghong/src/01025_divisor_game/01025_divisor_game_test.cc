#include "gtest/gtest.h"

#include <vector>

namespace SolutionTest01025 {

class Solution {
public:
    bool divisorGame(int N) {
        if (N < 2) return false;

        std::vector<bool> dp = {false, false};
        dp.resize(N+1);

        for (int i = 2; i <= N; i++)
        {
            for (int j = 1; j * j < i; j++)
            {
                if (0 == i % j && dp.at(i - j) == false)
                {
                    dp.at(i) = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_TRUE(sol.divisorGame(2));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_FALSE(sol.divisorGame(3));
}

TEST_F(SolutionTest, BoundedTest)
{
    EXPECT_FALSE(sol.divisorGame(1));
    EXPECT_TRUE(sol.divisorGame(1000));
}

}// namespace SolutionTest01025



