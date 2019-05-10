[[147 对链表进行插入排序]](https://leetcode-cn.com/problems/insertion-sort-list/submissions/)

问题：

> 对链表进行插入排序。
>
> ![img](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
> 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
> 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
>
>  
>
> **插入排序算法：**
>
> 1. 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
> 2. 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
> 3. 重复直到所有输入数据插入完为止。
>
>  
>
> **示例 1：**
>
> ```
> 输入: 4->2->1->3
> 输出: 1->2->3->4
> ```
>
> **示例 2：**
>
> ```
> 输入: -1->5->3->4->0
> 输出: -1->0->3->4->5
> ```



解析：

> 1、考察对链表的熟悉程度。
>
> 2、要照顾节点是否被丢弃。
>
> 3、节点的对比后如何进行位移。



解决方案：

1、

```python
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, x):
# self.val = x
# self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        res_head = ListNode(0)
        res_head.next = head
        res = res_head
        move_node_before = head
        move_node = head.next
        while move_node != None:
            if move_node.val >= move_node_before.val:
                move_node_before = move_node
                move_node = move_node.next
            else:
                while True:
                    if move_node.val > res_head.next.val:
                        res_head = res_head.next
                    else:
                        tmp_node = res_head.next
                        res_head.next = move_node
                        move_node_before.next = move_node.next
                        move_node.next = tmp_node
                        res_head = res
                        move_node = move_node_before
                        break
        return res.next
```

2、

```python
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, x):
# self val = x
# self.next = None

class Solution:
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        nums = []
        cur = head
        while cur:
            nums.append(cur.val)
            cur = cur.next
        nums.sort()
        cur = head
        for i in nums:
            cur.val = i
            cur = cur.next
        return head
```

