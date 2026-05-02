# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        r = head
        for _ in range(n):
            r = r.next
        l = head
        while r:
            # advance both r and l
            r = r.next
            temp = l
            l = l.next

        # reattach l-1 to l+1
        if l == head: return head.next

        temp.next = l.next

        return head