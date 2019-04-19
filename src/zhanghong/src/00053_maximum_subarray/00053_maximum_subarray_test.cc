
#include "gtest/gtest.h"

#include "00053_maximum_subarray.h"

namespace SolutionTest_00053 {

class SolutionTest00053 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest00053, Example)
{
    EXPECT_EQ(6, sol.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}));
}

TEST_F(SolutionTest00053, EmptyNums)
{
    EXPECT_EQ(0, sol.maxSubArray({}));
}

TEST_F(SolutionTest00053, SingleNums)
{
    EXPECT_EQ(-1, sol.maxSubArray({-1}));
}

TEST_F(SolutionTest00053, TwoNums)
{
    EXPECT_EQ(1, sol.maxSubArray({-2,1}));
}

};
