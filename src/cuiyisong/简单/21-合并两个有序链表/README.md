将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。  

示例：  
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4



解析：  

1、输入输出都是有序的，所以在组合新链表的时候需要对 value 进行大小判断。  

2、既可以在其中一个链表上进行拼接操作，也可以新建一个链表，看对内存的要求。  



# Definition for singly-linked list.  
# class ListNode:  
#     def __init__(self, x):  
#         self.val = x  
#         self.next = None  

class Solution:  
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:  
        if l1 == None and l2 == None:  
            return None  
        elif l1 == None:  
            return l2  
        elif l2 == None:  
            return l1  
        tmpNode = ListNode(0)  
        res = tmpNode  
        while True:  
            if l1.val < l2.val:  
                tmpNode.val = l1.val  
                l1 = l1.next  
                if None == l1:  
                    tmpNode.next = l2  
                    break  
                tmpNode.next = ListNode(0)  
                tmpNode = tmpNode.next  
            else:  
                tmpNode.val = l2.val  
                l2 = l2.next  
                if None == l2:  
                    tmpNode.next = l1  
                    break  
                tmpNode.next = ListNode(0)  
                tmpNode = tmpNode.next  
        return res