#include "00328_odd_even_linked_list.h"
#include "../kits/list2vec.h"
#include "../kits/vec2list.h"

#include <gtest/gtest.h>

#include <vector>
using namespace std;

class SolutionTest : public ::testing::Test 
{
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    vector<int> param{1, 2, 3, 4, 5};
    vector<int> exp{1, 3, 5, 2, 4};
    EXPECT_EQ(exp, list2vec(sol.oddEvenList(vec2list(param))));
}

TEST_F(SolutionTest, Example2)
{
    vector<int> param{2, 1, 3, 5, 6, 4, 7};
    vector<int> exp{2, 3, 6, 7, 1, 5, 4};
    EXPECT_EQ(exp, list2vec(sol.oddEvenList(vec2list(param))));
}

TEST_F(SolutionTest, Boudary1)
{
    vector<int> param{};
    vector<int> exp{};
    EXPECT_EQ(exp, list2vec(sol.oddEvenList(vec2list(param))));
}

TEST_F(SolutionTest, Boudary2)
{
    vector<int> param{1};
    vector<int> exp{1};
    EXPECT_EQ(exp, list2vec(sol.oddEvenList(vec2list(param))));
}

TEST_F(SolutionTest, WrongAnswer1)
{
    vector<int> param{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> exp{1, 3, 5 ,7, 2, 4, 6, 8};
    EXPECT_EQ(exp, list2vec(sol.oddEvenList(vec2list(param))));
}
