#include "00023_merge_k_sorted_lists.h"
/// Approach 1 - brute force
/// Explanation:
///     read all nodes in the lists into a vetor, 
///     then write them into a list
/// Strategy: Spaces swap Times
/// Time Complexity: O(NlogN)
/// Space Complexity: O(N)
/// Result: AC
/**
ListNode<int>* Solution::mergeKLists(vector<ListNode<int>*>& lists)
{
    vector<int> res;
    for (auto & list : lists)
    {
        while (list)
        {
            res.push_back(list->val);
            list = list->next;
        }
    }

    sort(res.begin(), res.end());
    ListNode<int> * cur = new ListNode<int>(-1);
    ListNode<int> * head = cur; 
    for (const int & e : res)
    {
        cur->next = new ListNode<int>(e);
        cur = cur->next;
    }

    cur = head;
    head = head->next;
    delete cur;
    cur = nullptr;

    return head;
}
**/

/// Approach 2 - pop queues
/// Explanation:
///     compare the fronts among lists and select the minimal repeatly. 
///     X X X X X X 
///     X X X X X X Y --- select Y (minimal) from the fonts among lists
///     X X X X X X 
///     ...
///     X X X X X X 
/// Strategy: Decrease and Conquer
/// Time Complexity: O(kN), where k is equal to lists.size()
/// Space Complexity: O(1)
/// Result: AC
/**
ListNode<int>* Solution::mergeKLists(vector<ListNode<int>*>& lists)
{
    if (lists.empty()) return nullptr;
    
    ListNode<int> * minPtr = new ListNode<int>(-1);
    ListNode<int> * head = minPtr;
    
    int minVal = INT_MAX;
    int minIdx = 0;
    while (minPtr)
    {
        minVal = INT_MAX;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] == nullptr) continue;
            if (lists[i]->val < minVal)
            {
                minVal = lists[i]->val;
                minIdx = i;

                minPtr->next = lists[i];                
            }
        }
        if (lists[minIdx]) lists[minIdx] = lists[minIdx]->next;
        minPtr = minPtr->next;
    }
   
    minPtr = head;
    head = head->next;
    delete minPtr;
    minPtr = nullptr;

    return head;
}
**/

/// Approach 2.1 - pop queues with minHeap
/// Explanation:
///     read all lists into a minHeap, 
///     then pop the top list from the heap and push its next when it is not null reaptly
/// Strategy: optimized from approach 2.0
/// Time Complexity: O(NlogK), where logK is the k in approach 2.0
/// Space Complexity: O(k), where k is equal to heap.size() for that the heap keeps k lists' head pointers
/// Result: AC
/**
#include <queue>
#include <functional>
ListNode<int>* Solution::mergeKLists(vector<ListNode<int>*>& lists)
{
    auto myGreater = [](ListNode<int> * l, ListNode<int> * r) { return l->val > r->val;};
    priority_queue<ListNode<int> *, vector<ListNode<int>*>, decltype(myGreater)> heap(myGreater);

    for (auto & list : lists) if (list != nullptr) heap.push(list);

    ListNode<int> * minPtr = new ListNode<int>(-1);
    ListNode<int> * head = minPtr;
    ListNode<int> * topPtr = nullptr;
    while (!heap.empty())
    {
        topPtr = heap.top();
        heap.pop();
        if (topPtr != nullptr && topPtr->next != nullptr) heap.push(topPtr->next);

        minPtr->next = topPtr;
        minPtr = minPtr->next;
    }

    minPtr = head;
    head = head->next;
    delete minPtr;
    minPtr = nullptr;
    
    return head;
}
**/

/// Approach 2.2 - merge one by one repeatly
/// Explanation:
///  X X X  ]
///  X X X  ] => X X X X X X ]
///  X X X                   ]=> X X X X X X X X X ]
///  X X X                                         ] => X X X X X X X X X X X X
/// Time Complexity: O(kN)
/// Space Complexity: O(k) = omega(N), where k would not be bigger than N in system stack space
/// Result: AC
/**
ListNode<int> * merge2lists(ListNode<int>* l, ListNode<int>* r)
{
    if (nullptr == l) return r;
    if (nullptr == r) return l;

    if (l->val < r->val)
    {
        l->next = merge2lists(l->next, r);
        return l;
    }
    else
    {
        r->next = merge2lists(l, r->next);
        return r;
    }
}
ListNode<int>* Solution::mergeKLists(vector<ListNode<int>*>& lists)
{
    ListNode<int> * l = lists.front();
    for (int i = 1; i < lists.size(); i++)
    {
        l = merge2lists(l, lists[i]);
    }

    return l;
}
**/
/// Approach 2.3 - dive(aready done) and conquer(just merge two sub-problems)
/// Explanation:
///  X X X ]
///  X X X ] => X X X X X X ]
///  X X X ] => X X X X X X ] => X X X X X X X X X X X X
///  X X X ] 
/// Time Complexity: O(kN)
/// Space Complexity: O(k) = omega(N), where k would not be bigger than N in system stack space
/// Result: AC

ListNode<int> * submerge(vector<ListNode<int>*> &lists, int left, int right)
{
    if (left == right) return lists[left];
    
    int mid = (left + right) >> 1;
    ListNode<int> * l = submerge(lists, left, mid);
    ListNode<int> * r = submerge(lists, mid+1, right);

    ListNode<int> * minPtr = new ListNode<int>(-1);
    ListNode<int> * head = minPtr;
    
    ListNode<int> * topPtr = nullptr;
    while (minPtr)
    {
        if (l == nullptr)
        {
            minPtr->next = r;
            minPtr = minPtr->next;
            break;
        }

        if (r == nullptr)
        {
            minPtr->next = l;
            minPtr = minPtr->next;
            break;
        }

        if (l->val < r->val)
        {
            minPtr->next = l;
            l = l->next;
        }
        else
        {
            minPtr->next = r;
            r = r->next;
        }

        minPtr = minPtr->next;
    }


    minPtr = head;
    head = head->next;
    delete minPtr;
    minPtr = nullptr;

    return head;
}

ListNode<int>* Solution::mergeKLists(vector<ListNode<int>*>& lists)
{
    return submerge(lists, 0, lists.size() - 1);
}