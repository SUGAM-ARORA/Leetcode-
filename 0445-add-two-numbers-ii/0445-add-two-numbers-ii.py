# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rev(self, head):
        if head is None:
            return None
        curr = head
        prev = None
        nex = None
        while curr is not None:
            nex = curr.next
            curr.next = prev
            prev = curr
            curr = nex
        return prev

    def rev2(self, head):
        if head is None:
            return None
        if head.next is None:
            return head
        new_head = self.rev2(head.next)
        head.next.next = head
        head.next = None
        return new_head

    def solve(self, head1, head2):
        car = 0
        p = ListNode(9)
        ans = p
        while head1 is not None or head2 is not None or car > 0:
            sum = car
            if head1 is not None:
                sum += head1.val
                head1 = head1.next
            if head2 is not None:
                sum += head2.val
                head2 = head2.next
            v = sum % 10
            car = sum // 10
            ans.next = ListNode(v)
            ans = ans.next
        return p.next

    def addTwoNumbers(self, l1, l2):
        l1rev = self.rev(l1)
        l2rev = self.rev2(l2)
        res = self.solve(l1rev, l2rev)
        return self.rev(res)
        