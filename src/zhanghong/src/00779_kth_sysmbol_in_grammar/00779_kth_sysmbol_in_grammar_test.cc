#include "00779_kth_sysmbol_in_brammar.h"

#include "gtest/gtest.h"

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(0, sol.kthGrammar(1, 1));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(0, sol.kthGrammar(2, 1));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ(1, sol.kthGrammar(2, 2));
}

TEST_F(SolutionTest, Example4)
{
    EXPECT_EQ(1, sol.kthGrammar(4, 5));
}

TEST_F(SolutionTest, BoundryCase)
{
    /// 536870912 == 2^29
    EXPECT_EQ(1, sol.kthGrammar(30, 536870912));
}