#ifndef __KITS_VEC2LIST_H
#define __KITS_VEC2LIST_H

#include "../headers/list_node.h"

#include <vector>

using namespace std;

template<typename T>
ListNode<T> * vec2list(const vector<T> & vec)
{
    ListNode<T> * cur = new ListNode<int>(0);
    ListNode<T> * head = cur;
    for (const T & e : vec)
    {
        ListNode<T> * node = new ListNode<T>(e);
        cur->next = node;
        cur = cur->next;
    }

    ListNode<T> * tmp = head;
    head = head->next;
    delete tmp;
    tmp = nullptr;

    return head;
}


#endif