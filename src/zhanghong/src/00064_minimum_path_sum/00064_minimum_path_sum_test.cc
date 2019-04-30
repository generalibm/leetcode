#include "00064_minimum_path_sum.h"

#include "gtest/gtest.h"

class SolutionTest64 : public ::testing::Test {
protected:
    Solution64::Solution sol;
};

TEST_F(SolutionTest64, Example1)
{
    EXPECT_EQ(7, sol.minPathSum( { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } }));
}

TEST_F(SolutionTest64, HeapBufferOverflow1)
{
    EXPECT_EQ(6, sol.minPathSum( { { 1, 2, 5 }, { 3, 2, 1 } }));
}



