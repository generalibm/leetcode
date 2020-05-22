#include "01452_people_whoes_list_of_favorite_companies_is_not_a_subset_of_another_list.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test 
{
protected:
    Solution sol;
};

TEST_F(SolutionTest, Exmaple1)
{
    vector<vector<string>> param{{"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}};
    vector<int> ret{0,1,4};
    EXPECT_EQ(ret, sol.peopleIndexes(param));
}

TEST_F(SolutionTest, Example2)
{
    vector<vector<string>> param{{"leetcode","google","facebook"},{"leetcode","amazon"},{"facebook","google"}};
    vector<int> ret{0,1};
    EXPECT_EQ(ret, sol.peopleIndexes(param));
}

TEST_F(SolutionTest, Example3)
{
    vector<vector<string>> param{{"leetcode"},{"google"},{"facebook"},{"amazon"}};
    vector<int> ret{0,1, 2, 3};
    EXPECT_EQ(ret, sol.peopleIndexes(param));
}