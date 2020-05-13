#include "gtest/gtest.h"
#include "00733_flood_fill.h"

class SolutionTest : public ::testing::Test 
{
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    vector<vector<int>> res{{2,2,2},{2,2,0},{2,0,1}};
    vector<vector<int>> param{{1,1,1},{1,1,0},{1,0,1}};
    EXPECT_EQ(res, 
               sol.floodFill(param, 
                                1, 
                                1, 
                                2));
}

TEST_F(SolutionTest, RuntimeError1)
{
    vector<vector<int>> res{{0,0,0},{0,1,1}};
    vector<vector<int>> param{{0,0,0},{0,1,1}};
    EXPECT_EQ(res, 
               sol.floodFill(param, 
                                1, 
                                1, 
                                1));
}


