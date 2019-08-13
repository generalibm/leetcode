#include "gtest/gtest.h"

#include "00215_Kth_largest_element_in_an_array.h"

namespace SolutionTest00215 {

class SolutionTest215 : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest215, Example1)
{
    EXPECT_EQ(5, sol.findKthLargest({3,2,1,5,6,4}, 2));
}

TEST_F(SolutionTest215, Example2)
{
    EXPECT_EQ(4, sol.findKthLargest({3,2,3,1,2,4,5,5,6}, 4));
}

}




