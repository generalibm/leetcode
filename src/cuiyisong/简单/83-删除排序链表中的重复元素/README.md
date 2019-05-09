[[83 删除排序链表中的重复元素]](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

问题：

> 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
>
> **示例 1:**
>
> ```
> 输入: 1->1->2
> 输出: 1->2
> ```
>
> **示例 2:**
>
> ```
> 输入: 1->1->2->3->3
> 输出: 1->2->3
> ```



解析：

> 有以下几种方法：
>
> 1、遍历，存储每个值，然后判断是否重复，再遍历删除。
>
> 2、递归，记录每个值。



解决方案：

```python
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, x):
# self.val = x
# self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        else:
            tmpHead = head
            tmpHeadNext = head.next
            while tmpHeadNext:
                if tmpHead.val == tmpHeadNext.val:
                    tmpHeadNext = tmpHeadNext.next
                    tmpHead.next = tmpHeadNext
                else:
                    tmpHeadNext = tmpHeadNext.next
                    tmpHead = tmpHead.next
            return head
```

