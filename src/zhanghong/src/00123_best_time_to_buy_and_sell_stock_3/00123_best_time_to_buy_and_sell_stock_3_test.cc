#include "gtest/gtest.h"

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        return 6;
    }
};

class SolutionTest123 : public ::testing::Test {
protected:
    Solution sol;
};


TEST_F(SolutionTest123, Example1)
{
    EXPECT_EQ(6, sol.maxProfit({3,3,5,0,0,3,1,4}));
}

