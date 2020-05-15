## 23. Merge k Sorted Lists[Hard]

Merge *k* sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**Example:**

```json
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
```

## Solution Analysis
### Approach 1 - intuiative approach
**Strategy:** Brute force, spaces swap times
**Explanation:**
>     Read all nodes in the lists into a vetor, 
>     then write them into a list.

```c++
ListNode* mergeKLists(vector<ListNode*>& lists)
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
    ListNode * minPtr = new ListNode(-1);
    ListNode * head = minPtr; 
    for (const int & e : res)
    {
        minPtr->next = new ListNode(e);
        minPtr = minPtr->next;
    }

    minPtr = head;
    head = head->next;
    delete minPtr;
    minPtr = nullptr;

    return head;
}
```
- **Time Complexity:** O(NlogN)
- **Space Complexity:** O(N)
- **Result:** AC

### Approach 2 - pop queues
**Strategy:** Decrease and Conquer
**Explanation:**
>     To compare the fronts among lists and select the minimal repeatly. 
>     X X X X X X 
>     X X X X X X Y --- select Y (minimal) from the fonts among lists
>     X X X X X X 
>     ...
>     X X X X X X 

```c++
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if (lists.empty()) return nullptr;
    
    ListNode * minPtr = new ListNode(-1);
    ListNode * head = minPtr;
    
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
```
- **Time Complexity:** O(kN), where k is equal to lists.size()
- **Space Complexity:** O(1)
- **Result:** AC

### Approach 2.1 - optimized from approach 2
**Strategy:** Get minimal in ***log(N)*** time with a minHeap
**Explanation:**

>     Read all lists into a minHeap, 
>     then pop the top list from the heap and push its next reaptly.

```c++
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    auto myGreater = [](ListNode * l, ListNode * r) { return l->val > r->val;};
    priority_queue<ListNode *, vector<ListNode*>, decltype(myGreater)> heap(myGreater);

    for (auto & list : lists) if (list != nullptr) heap.push(list);

    ListNode * minPtr = new ListNode(-1);
    ListNode * head = minPtr;
    ListNode * topPtr = nullptr;
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
```
- **Time Complexity:** O(NlogK), where logK is the k in approach 2.0
- **Space Complexity:** O(k), where k is equal to heap.size() for that the heap keeps k lists' head pointers
- **Result:** AC

### Approach 2.2 - Decrease and Conquer, optimized from approach 2
**Strategy:** Merge one by one repeatly 
**Explanation:**

>  X X X  ]
>  X X X  ] => X X X X X X ]
>  X X X                   ]=> X X X X X X X X X ]
>  X X X                                         ] => X X X X X X X X X X X X

```c++
ListNode * merge2lists(ListNode* l, ListNode* r)
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
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    ListNode * l = lists.front();
    for (int i = 1; i < lists.size(); i++)
    {
        l = merge2lists(l, lists[i]);
    }

    return l;
}
```
- **Time Complexity:** O(kN)
- **Space Complexity:** O(k) = omega(N), where k would not be bigger than N in system stack space
- **Result:** AC

### Approach 2.3 - Dive and Conquer, optimized from approach 2.2 
**Strategy:** Dive(aready done) and Conquer(just merge two sub-problems)
**Explanation:**
>  X X X ]
>  X X X ] => X X X X X X ]
>  X X X ] => X X X X X X ] => X X X X X X X X X X X X
>  X X X ] 

```c++
ListNode * submerge(vector<ListNode*> &lists, int left, int right)
{
    if (left == right) return lists[left];
    
    int mid = (left + right) >> 1;
    ListNode * l = submerge(lists, left, mid);
    ListNode * r = submerge(lists, mid+1, right);

    ListNode * minPtr = new ListNode(-1);
    ListNode * head = minPtr;
    
    ListNode * topPtr = nullptr;
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

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    return submerge(lists, 0, lists.size() - 1);
}
```
- **Time Complexity:** O(kN)
- **Space Complexity:** O(k) = omega(N), where k would not be bigger than N in system stack space
- **Result:** AC
