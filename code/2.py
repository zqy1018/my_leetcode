# 使用基础链表进行操作


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res = ListNode(0)
        head = res
        x = 0
        while l1 != None and l2 != None:
            x += l1.val + l2.val
            node = ListNode(x % 10)
            res.next = node; res = node
            x //= 10
            l1 = l1.next; l2 = l2.next
        while l1 != None:
            x += l1.val
            node = ListNode(x % 10)
            res.next = node; res = node
            x //= 10
            l1 = l1.next
        while l2 != None:
            x += l2.val
            node = ListNode(x % 10)
            res.next = node; res = node
            x //= 10
            l2 = l2.next
        if x:
            node = ListNode(1)
            res.next = node; res = node
        while head.next != None:
            head = head.next
            print(head.val, end = '')
        return head.next