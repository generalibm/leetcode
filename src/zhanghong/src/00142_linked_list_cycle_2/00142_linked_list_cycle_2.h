
#ifndef SRC_ZHANGHONG_SRC_00142_LINKED_LIST_CYCLE_2_00142_LINKED_LIST_CYCLE_2_H_
#define SRC_ZHANGHONG_SRC_00142_LINKED_LIST_CYCLE_2_00142_LINKED_LIST_CYCLE_2_H_


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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)               // there is a cycle
            {
                while (slow != entry)       // found the entry location
                {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;       // there is no cycle
    }
};



#endif /* SRC_ZHANGHONG_SRC_00142_LINKED_LIST_CYCLE_2_00142_LINKED_LIST_CYCLE_2_H_ */
