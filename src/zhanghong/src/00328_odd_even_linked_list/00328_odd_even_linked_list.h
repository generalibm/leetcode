#ifndef __SRC_00328_ODD_EVEN_LINKED_LIST
#define __SRC_00328_ODD_EVEN_LINKED_LIST

#include "../headers/list_node.h"

class Solution
{
public:
    ListNode<int> *oddEvenList(ListNode<int> *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode<int> *x = head;
        ListNode<int> *y = head->next;
        ListNode<int> *evenHead = head->next;

        while (x->next && y->next)
        {
            x->next = x->next->next;
            x = x->next;

            y->next = y->next->next;
            y = y->next;
        }

        x->next = evenHead;

        return head;
    }
};

#endif