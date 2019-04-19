#include "gtest/gtest.h"

#include "00152_maximum_product_subarray.h"

namespace SolutionTest_000152 {

class SolutionTest00152 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest00152, Example1)
{
    EXPECT_EQ(6, sol.maxProduct({2,3,-2,4}));
}

TEST_F(SolutionTest00152, Example2)
{
    EXPECT_EQ(0, sol.maxProduct({-2,0,-1}));
}

TEST_F(SolutionTest00152, WrongAnswer1)
{
    EXPECT_EQ(24, sol.maxProduct({2,-5,-2,-4,3}));
}

};



