## 142. Linked List Cycle II [Medium]

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.

**Note:** Do not modify the linked list.

**Example 1:**

```markdown
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
```

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

**Example 2:**

```markdown
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
```

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

**Example 3:**

```markdown
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
```

![img](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

**Follow up**:
 Can you solve it without using extra space?



### Solution Analysis

**Algorithm descriptions**

-   **Step 1: Determine whether there is a cycle**

     1.1) Using a slow pointer that move forward 1 step  each time

     1.2) Using a fast  pointer that move forward 2 steps each time

     1.3) If the slow pointer and fast pointer both point to the same location after several moving steps, there is a cycle;

     1.4) Otherwise, `if (fast->next == NULL || fast->next->next == NULL)`, there has no cycle.

-   **Step 2: If there is a cycle, return the entry location of the cycle**

     2.1) `L1` is defined as the distance between the head point and entry point

     2.2) `L2` is defined as the distance between the entry point and the meeting point

-   **Conclusion**
    
    -   Distance traveled by slow when they meet: `L1+L2`
    -   Distance traveled by fast when they meet: `L1+L2+x+L2`, where `x` is the  remaining length of the cycle (meeting point to start of the cycle).

>   2(L1+L2)   = L1+L2+x+L2
 => 2L1 + 2L2 = L1+2L2+x
 => x = L1 

- so we need to move `L1` steps from the current meeting point to reach the entry point of the cycle.

**Time**: O(n)

**Space**: O(1)