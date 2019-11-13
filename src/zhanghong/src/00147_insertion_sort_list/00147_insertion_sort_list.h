
#ifndef SRC_ZHANGHONG_SRC_00147_INSERTION_SORT_LIST_00147_INSERTION_SORT_LIST_H_
#define SRC_ZHANGHONG_SRC_00147_INSERTION_SORT_LIST_00147_INSERTION_SORT_LIST_H_

#include <climits>

namespace Solution147 {

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
            : val(x),
              next(nullptr)
    {
    }
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode res = ListNode(INT_MIN);
        res.next = head;

        ListNode * cur_prev = head;
        ListNode * cur = cur_prev->next;

        ListNode * pos = &res;

        for (; cur != nullptr; cur_prev = cur_prev->next, cur = cur_prev->next)
        {
            while (pos != cur && pos->val <= cur->val)
            {
                pos = pos->next;
            }

            cur_prev->next = cur->next;
            cur->next = pos->next;
            pos->next = cur;

            pos = &res;
        }

        return res.next;
    }

};

}



#endif /* SRC_ZHANGHONG_SRC_00147_INSERTION_SORT_LIST_00147_INSERTION_SORT_LIST_H_ */
