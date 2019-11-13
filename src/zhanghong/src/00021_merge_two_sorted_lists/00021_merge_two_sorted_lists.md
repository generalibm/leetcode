## 21. Merge Two Sorted Lists [Easy]

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

**Example:**

```bash
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
```

### Solution Analysis

**Overview** 

For merging sorted sequences into one, we may usually treat it just like what `mergeSort` does, which utilizes `Dived and Conquer`. In this senara, it is easy because there are only two lists, actually that is what `Dived and Conquer` usually does -- diving the problem into two subproblems and merge them into one after the both are done, and it is not difficult  to come up with a intuitive approach like *Approach 1*, but it could also make a lot of troubles when it is beyond two even much more like `n` (a undecided number such a dynamic vector).

To address that dynamic demand, and also meet the demand for the present tivial case(two sorted sequences), a *recursive approach*, illustrated in the *approach 2*, are highly recommanded which can be more extensive and flexible in *merging proplem*.

As we all know that *recursive approach* always means inefficient, but not many approaches could provide a intuitive understanding of the realistic quizzes such as *tree traverse, net traverse, and some classic string problems*. When we realize that it is a *recursive problem*, sometimes we can also rewrite it into a nonrecursive version which is usually called *Decrease and Conquer*. But unfortunately, it is too limited do so just like *Approach 2*, in which there are two branches to decide two opposite directions, which makes it merely impossible to rewrite into a nonrecursive version.



**Approach 1**

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode * tail = (l1->val < l2->val ? l1 : l2);
        ListNode * head = tail;
        
        if (tail == l1) l1 = l1->next;
        else l2 = l2->next;
       
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {                
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;;
            } 
            tail = tail->next;          
        }
        
        if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;
        
        return head;
    }    
};
```



**Approach 2**

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
      
        if (l1->val<l2->val) 
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else 
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```

