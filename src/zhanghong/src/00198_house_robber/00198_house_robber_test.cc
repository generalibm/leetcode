#include "gtest/gtest.h"

#include <vector>

using namespace std;

namespace SolutionTest00198 {

class Solution {
public:
    int rob(const vector<int>& nums) {
        if (nums.empty()) return 0;

        vector<int> dp(nums.size());

        int cur = nums.front();
        for (size_t i = 0; i < nums.size(); i++)
        {
            cur = max(cur, nums[i]);
            dp[i] = cur;
        }

        for (size_t i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
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
    EXPECT_EQ(4, sol.rob({1,2,3,1}));
}

TEST_F(SolutionTest, Exmaple2)
{
    EXPECT_EQ(12, sol.rob({2,7,9,3,1}));
}

TEST_F(SolutionTest, WrongAnswer1)
{
    EXPECT_EQ(4, sol.rob({2, 1, 1, 2}));
}

TEST_F(SolutionTest, Empty)
{
    EXPECT_EQ(0, sol.rob({}));
}

}
