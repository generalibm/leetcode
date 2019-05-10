[[707 设计链表]](https://leetcode-cn.com/problems/design-linked-list/submissions/)

问题：

> 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：`val` 和 `next`。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
>
> 在链表类中实现这些功能：
>
> - get(index)：获取链表中第 `index` 个节点的值。如果索引无效，则返回`-1`。
> - addAtHead(val)：在链表的第一个元素之前添加一个值为 `val` 的节点。插入后，新节点将成为链表的第一个节点。
> - addAtTail(val)：将值为 `val` 的节点追加到链表的最后一个元素。
> - addAtIndex(index,val)：在链表中的第 `index` 个节点之前添加值为 `val`  的节点。如果 `index` 等于链表的长度，则该节点将附加到链表的末尾。如果 `index` 大于链表长度，则不会插入节点。
> - deleteAtIndex(index)：如果索引 `index` 有效，则删除链表中的第 `index` 个节点。
>
>  
>
> **示例：**
>
> ```
> MyLinkedList linkedList = new MyLinkedList();
> linkedList.addAtHead(1);
> linkedList.addAtTail(3);
> linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
> linkedList.get(1);            //返回2
> linkedList.deleteAtIndex(1);  //现在链表是1-> 3
> linkedList.get(1);            //返回3
> ```
>
>  
>
> **提示：**
>
> - 所有值都在 `[1, 1000]` 之内。
> - 操作次数将在  `[1, 1000]` 之内。
> - 请不要使用内置的 LinkedList 库。



解析：

> 1、采用 list 作为存储，因为其可以做到链表的功能。
>
> 2、采用自定义一个 node 的方法，然后根据需求来进行完善。



解决方案：

1、

```python
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class MyLinkedList:
    def __init__(self):
        self.head = Node(0)

    def get(self, index: int) -> int:
        if index < 0:
            return -1
        i = 0
        if self.head.next == None:
            return -1
        head = self.head.next
        while (i < index):
            if head.next != None:
                head = head.next
                i += 1
            else:
                return -1
        return -1 if head == None else head.value

    def addAtHead(self, val: int) -> None:
        head = self.head.next
        new_node = Node(val)
        new_node.next = head
        self.head.next = new_node

    def addAtTail(self, val: int) -> None:
        head = self.head
        while(head.next != None):
            head = head.next
        head.next = Node(val)

    def addAtIndex(self, index: int, val: int) -> None:
        if index <= 0:
            self.addAtHead(val)
            return
        i = 0
        head = self.head
        while(i < index):
            if head.next != None:
                head = head.next
                i += 1
            else:
                return
        new_node = Node(val)
        new_node.next = head.next
        head.next = new_node

    def deleteAtIndex(self, index: int) -> None:
        if index < 0:
            return
        i = 0
        if self.head.next == None:
            return
        head = self.head
        while(i < index):
            if head.next != None:
                head = head.next
                i += 1
            else:
                return
        if head.next == None:
            return
        else:
            head.next = head.next.next
```

2、

```python
class MyLinkedList(object):
    def __init__(self):
        self.lst = []

    def get(self, index):
        if index > len(self.lst) - 1 or index < 0:
            return -1
        return self.lst[index]

    def addAtHead(self, val):
        self.lst.insert(0, val)

    def addAtTail(self, val):
        self.lst.append(val)

    def addAtIndex(self, index, val):
        if index > len(self.lst):
            return 
        elif index == len(self.lst):
            self.lst.append(val)
        else:
            self.lst.insert(index, val)

    def deleteAtIndex(self, index):
        if index > len(self.lst) - 1 or index < 0:
            return 
        self.lst.pop(index)
```



