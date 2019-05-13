#include "00148_sort_list.h"

namespace Solution148 {

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x)
            : val(x),
              next(nullptr)
    {
    }

    bool operator<(const ListNode & node)
    {
        return this->val < node.val;
    }

};

ListNode * buildList(std::vector<int> vec)
{
    if (vec.empty())
        return nullptr;

    ListNode * head = new ListNode(vec.front());
    ListNode * cur = head;

    for (size_t i = 1; i < vec.size(); i++)
    {
        ListNode * node = new ListNode(vec[i]);
        cur->next = node;
        cur = node;
    }

    return head;
}

void DestroyList(ListNode * head)
{
    ListNode * cur = head;
    ListNode * deleted = nullptr;
    while (cur != nullptr)
    {
        deleted = cur;
        cur = cur->next;
        delete deleted;
    }
}

void showList(ListNode * head, ListNode * tail = nullptr)
{
    for (ListNode * cur = head; cur != tail; cur = cur->next)
    {
        std::cout << cur->val << "->";
    }
    std::cout << "end" << std::endl;
}

std::vector<int> ListToVector(ListNode * head)
{
    std::vector<int> vec;
    for (ListNode * cur = head; cur != nullptr; cur = cur->next)
    {
        vec.push_back(cur->val);
    }

    return vec;
}



void Solution148::Solution::quickSort(ListNode * head, ListNode * left,
        ListNode * right)
{
    if (left == right)
        return;

    ListNode * mid = left;

    for (ListNode * cur = left->next; cur != right; cur = cur->next)
    {
        if (cur->val < left->val)
        {
            mid = mid->next;
            std::swap(cur->val, mid->val);
        }
    }

    std::swap(mid->val, left->val);

    quickSort(head, left, mid);
    quickSort(head, mid->next, right);
}

ListNode* Solution148::Solution::sortList(ListNode* head)
{
    quickSort(head, head, nullptr);
    return head;
}

void Solution148::Solution::test(std::vector<int> vec)
{
    ListNode *head = buildList(vec);
    showList(head);

    quickSort(head, head, nullptr);
    showList(head);

    DestroyList(head);
}

}//namespace
