#include "01673_find_the_most_competitive_subsequence.h"

#include "gtest/gtest.h"

class SolutionTest1673 : public ::testing::Test {
protected:
    Solution sol;  
};

TEST_F(SolutionTest1673, Example1)
{
    vector<int> res{2,6};
    EXPECT_EQ(res, sol.mostCompetitive({3,5,2,6}, 2));
}

TEST_F(SolutionTest1673, Example2)
{
    vector<int> res{2,3,3,5,4,9,6};
    EXPECT_EQ(res, sol.mostCompetitive({2,4,3,3,5,4,9,6}, 7));
}

TEST_F(SolutionTest1673, Example3)
{
    vector<int> res{2,3,3,4};
    EXPECT_EQ(res, sol.mostCompetitive({2,4,3,3,5,4,9,6}, 4));
}

TEST_F(SolutionTest1673, Example4)
{

}