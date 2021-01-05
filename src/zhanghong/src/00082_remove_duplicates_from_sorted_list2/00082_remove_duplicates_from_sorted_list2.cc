#include "00082_remove_duplicates_from_sorted_list2.h"

#include <limits.h>
#include <iostream>
using namespace std;
/// approach 1
#if 0
ListNode<int> *Solution82::Solution::deleteDuplicates(ListNode<int> *head)
{

    ListNode<int> *top = new ListNode<int>(INT_MIN);
    top->next = head;
    ListNode<int> *prev = top;
    ListNode<int> *cur = prev->next;

    while (cur != nullptr)
    {
        cout << cur->val << endl;
        if (cur->next == nullptr)
        {
            if (cur->val == top->val)
            {
                delete cur;
                cur = nullptr;
                prev->next = nullptr;
            }
            break;
        }
        // cur->next != nullptr
        if (cur->val == cur->next->val || cur->val == top->val)
        {
            top->val = cur->val;

            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
        else
        {
            prev = prev->next;
            cur = cur->next;
        }
    }

    head = top->next;

    delete top;
    top = nullptr;
    return head;
}
#endif

ListNode<int> *Solution82::Solution::deleteDuplicates(ListNode<int> *head)
{
    if (!head or !head->next) return head;

    if (head->val == head->next->val)
    {
        int val = head->val;
        while (head and head->val == val)
            head = head->next;
        return deleteDuplicates(head);
    }
    else
    {
        head->next =deleteDuplicates(head->next);
        return head;
    }
}