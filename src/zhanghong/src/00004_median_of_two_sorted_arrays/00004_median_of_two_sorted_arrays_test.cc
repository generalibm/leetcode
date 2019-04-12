#include "gtest/gtest.h"

#include "00004_median_of_two_sorted_arrays.h"

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, ExampleTest1)
{
    EXPECT_EQ(2.0, sol.findMedianSortedArrays({1, 3}, {2}));
}

TEST_F(SolutionTest, ExampleTest2)
{
    EXPECT_EQ(2.5, sol.findMedianSortedArrays({1, 2}, {3, 4}));
}

TEST_F(SolutionTest, OneEmptyTest)
{
    EXPECT_EQ(3.5, sol.findMedianSortedArrays({}, {3, 4}));
}

TEST_F(SolutionTest, AllElemLessThanOtherTest)
{
    EXPECT_EQ(3.0, sol.findMedianSortedArrays({1, 2, 3}, {4, 5}));
}
