[[234 回文链表]](https://leetcode-cn.com/problems/palindrome-linked-list/)

问题：

> 请判断一个链表是否为回文链表。
>
> **示例 1:**
>
> ```
> 输入: 1->2
> 输出: false
> ```
>
> **示例 2:**
>
> ```
> 输入: 1->2->2->1
> 输出: true
> ```
>
> **进阶：**
> 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

解析：

> 1、最简单的方法，将数据从头到尾读出来存储到一个 list 中，反转 list，对比前后 list 是否相同。
>
> (注：最好不要用reverse，因为列表的赋值并非创造一个新的列表，而是指向原列表)
>
> 例：
>
> ```python
> 	list_1= [1, 2, 3, 4, 5]
> 	a = list_1
> 	b = list_1
> 	b.reverse()
> 	print ('a = ')
> 	print (a)
> 	print ('b = ')
> 	print (b)
> 	结果：
> 		a = [5, 4, 3, 2, 1]
> 		b = [5, 4, 3, 2, 1]
> ```
>
> 2、采用快慢指针，选取到中间值，从中间值将后面的链表翻转，然后进行对比。

解决方案：

```python
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, x):
# self.val = x
# self.next = None
#耗时112ms
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        tmp_list = []
        if head == None or head.next == None:
            return True
        while head:
            tmp_list.append(head.val)
            head = head.next
        return tmp_list == tmp_list[::-1]
```

```python
# Definition for singly-linked list.
# class ListNode:
# def __init__(self, x):
# self.val = x
# self.next = None
#耗时72ms
class Solution:
    def isPalindrome(self, head: 'ListNode') -> 'bool':
        def reverse(h: ListNode) -> ListNode:
            prev = None
            while h:
                next = h.next
                h.next = prev
                prev, h = h, next
            return prev
    fast, slow = head, head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    slow = slow.next if fast else slow
    p, q = head, reverse(slow)
    while q:
        if p.val != q.val:
            return False
        p, q = p.next, q.next
    return True
```

