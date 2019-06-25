#include "gtest/gtest.h"
#include "00213_house_robber_2.h"


using namespace Solution00213;

namespace SolutionTest00213 {

class SolutionTest : public ::testing::Test {
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    EXPECT_EQ(3, sol.rob( { 2, 3, 2 }));
}

TEST_F(SolutionTest, Example2)
{
    EXPECT_EQ(4, sol.rob( { 1, 2, 3, 1 }));
}

TEST_F(SolutionTest, Example3)
{
    EXPECT_EQ(7, sol.rob( { 1, 5, 2, 1, 2 }));
}

}



