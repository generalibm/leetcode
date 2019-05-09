[[92 反转链表2]](https://leetcode-cn.com/problems/reverse-linked-list-ii/submissions/)

问题：

> 反转从位置 *m* 到 *n* 的链表。请使用一趟扫描完成反转。
>
> **说明:**
> 1 ≤ *m* ≤ *n* ≤ 链表长度。
>
> **示例:**
>
> ```
> 输入: 1->2->3->4->5->NULL, m = 2, n = 4
> 输出: 1->4->3->2->5->NULL
> ```



解析：

> 1、说白了就是考察对链表的熟悉程度。
>
> 2、三个指针来回倒。
>
> 3、注意不要指向死循环。



解决方案：

```python
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, x):
# self.val = x
# self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        tmp_head = ListNode(0)
        res = tmp_head
        tmp_head.next = head
        for i in range (1, m):
            tmp_head = tmp_head.next
        tmp_start = tmp_head.next
        tmp_node = tmp_start.next
        for j in range (m, n):
            tmp_start.next = tmp_node.next
            tmp_node.next = tmp_head.next
            tmp_head.next = tmp_node
            tmp_node = tmp_start.next
        return res.next
```

