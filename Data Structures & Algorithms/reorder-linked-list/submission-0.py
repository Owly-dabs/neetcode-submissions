# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        sp: ListNode = head
        fp: ListNode = head.next

        while fp != None and fp.next != None:
            sp = sp.next
            fp = fp.next.next
        
        # Reverse 
        second = sp.next
        prev = sp.next = None

        while second:
            temp = second.next
            second.next = prev
            prev = second
            second = temp
            
        second = prev
        first = head
        
        while second:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp1
            first = tmp1
            second = tmp2