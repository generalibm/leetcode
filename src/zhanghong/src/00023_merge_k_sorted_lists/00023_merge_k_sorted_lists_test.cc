#include "00023_merge_k_sorted_lists.h"
#include "../kits/vec2list.h"
#include "../kits/list2vec.h"

#include <gtest/gtest.h>

class SolutionTest : public ::testing::Test 
{
protected:
    Solution sol;
};

TEST_F(SolutionTest, Example1)
{
    vector<ListNode<int>*> lists;

    vector<vector<int>> vecs{{1,4,5},{1,3,4},{2,6}};
    for (const auto & vec : vecs)
    {
        ListNode<int> * list = vec2list(vec);
        lists.push_back(list);
    }

    vector<int> exp{1,1,2,3,4,4,5,6};

    EXPECT_EQ(exp, list2vec(sol.mergeKLists(lists)));
}

TEST_F(SolutionTest, Boudary1)
{
    vector<ListNode<int>*> lists;

    vector<vector<int>> vecs{{}};
    for (const auto & vec : vecs)
    {
        ListNode<int> * list = vec2list(vec);
        lists.push_back(list);
    }

    vector<int> exp{};

    EXPECT_EQ(exp, list2vec(sol.mergeKLists(lists)));
}

TEST_F(SolutionTest, Boudary2)
{
    vector<ListNode<int>*> lists;

    vector<vector<int>> vecs{{},{}};
    for (const auto & vec : vecs)
    {
        ListNode<int> * list = vec2list(vec);
        lists.push_back(list);
    }

    vector<int> exp{};

    EXPECT_EQ(exp, list2vec(sol.mergeKLists(lists)));
}
