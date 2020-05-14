#ifndef __KITS_LIST_2_VEC_H
#define __KITS_LIST_2_VEC_H

#include "../headers/list_node.h"

#include <vector>
using namespace std;

template<typename T>
vector<T> list2vec(ListNode<T> * list)
{
    vector<T> res;
    while (list)
    {
        res.push_back(list->val);
        list = list->next;
    }

    return res;
}

#endif