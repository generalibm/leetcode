#include "00148_sort_list.h"

#include "gtest/gtest.h"


class SolutionTest148 : public ::testing::Test {
protected:
    Solution148::Solution sol;
};

TEST_F(SolutionTest148, Example1)
{
    sol.test({4,2,1,3});
//    EXPECT_EQ({1, 2, 3, 4}, ListToVector(sol.sortList({4,2,1,3})));
}

TEST_F(SolutionTest148, Example2)
{
    sol.test({-1, 5, 3, 4, 0});
}




