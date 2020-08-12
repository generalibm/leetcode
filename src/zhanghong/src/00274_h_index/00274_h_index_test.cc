#include "00274_h_index.h"
#include "gtest/gtest.h"

namespace SolutionTest00274 {

class SolutionTest : public ::testing::Test {
    protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    vector<int> param{0,1,3,5,6};
    EXPECT_EQ(3, sol.hIndex(param));
}

TEST_F(SolutionTest, WrongAnswer1)
{
    vector<int> param{0};
    EXPECT_EQ(0, sol.hIndex(param));
}

};