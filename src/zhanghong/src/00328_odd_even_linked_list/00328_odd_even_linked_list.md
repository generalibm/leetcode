## 328. Odd Even Linked List[Medium]

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

**Example 1:**
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

**Example 2:**
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

***Note:***
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

## Solution Analysis
### Approach 1
**Strategy:** Similar to delete a node in a linked list
**Explanation:**
How can we do if we want to delete the second node from the linked list?
>   1-->2-->3
We just make the firt node's next points the third one!
>    _______
>   |       |
>   1   2   3
cpp codes can be like this:
```c++
    x->next = x->next->next;
    x = x->next;
```
Based on the obove, we can figure out the problem by using two pointers.
Let deal with problem like the following one:
> 1-->2-->3-->4
The idea is to make x points to the first node and y points to second one, then just like delete operator.
>  _______
> |       |
> 1   2   3   4 
>     |       |
>      -------
cpp codes can be like this:
```c++
    while (x->next && y->next)
    {
        x->next = x->next->next;
        x = x->next;

        y->next = y->next->next;
        y = y->next;
    }
```
So, the source code to fix the problem can be like this:
```c++
ListNode* oddEvenList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) return head;
            
    ListNode * x = head;
    ListNode * y = head->next;
    ListNode * evenTop = head->next;
    
    while (x->next && y->next)
    {
        x->next = x->next->next;
        x = x->next;
        
        y->next = y->next->next;
        y = y->next;
    }
    
    x->next = evenTop;        
    
    return head;
}

```
**Time Complexity:** O(N)
**Space Complexity:** O(1)
**Result:** AC