
#include "gtest/gtest.h"

#include "00085_maximal_rectangle.h"

class SolutionTest85 : public ::testing::Test {
protected:
    Solution85::Solution sol;
};

TEST_F(SolutionTest85, Example1)
{
    EXPECT_EQ(6, sol.maximalRectangle({{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}));
}




