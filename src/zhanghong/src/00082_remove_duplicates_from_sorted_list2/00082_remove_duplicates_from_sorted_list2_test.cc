#include "gtest/gtest.h"
#include "../kits/list2vec.h"
#include "../kits/vec2list.h"

#include "00082_remove_duplicates_from_sorted_list2.h"

class SolutionTest82 : public ::testing::Test {
protected:
    Solution82::Solution sol;
};

TEST_F(SolutionTest82, Example1)
{
    vector<int> param{1, 2};
    vector<int> listParam{1,2,3,3,4,4,5,5,5};
    ListNode<int> * head = vec2list(listParam);
    EXPECT_EQ(param, list2vec(sol.deleteDuplicates(head)));
}