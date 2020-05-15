#ifndef __23_MERGE_K_SORTE_LIST_H
#define __23_MERGE_K_SORTE_LIST_H

#include "../headers/list_node.h"

#include <vector>

using namespace std;


class Solution
{
public:
    ListNode<int>* mergeKLists(vector<ListNode<int>*> & lists);
};

#endif