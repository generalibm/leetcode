#ifndef __HEADERS_LIST_NODE_H
#define __HEADERS_LIST_NODE_H

template<typename T>
struct ListNode
{
    T val;
    ListNode * next;
    ListNode(T x) : val(x), next(nullptr){}
    ListNode(T x, ListNode * n) : val(x), next(n) {}
};

#endif
