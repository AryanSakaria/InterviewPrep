# https://leetcode.com/problems/merge-two-sorted-lists/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None: 
            return l1
        
        if l1.val < l2.val:
            head = ListNode(l1.val)
            l1 = l1.next
        else:
            head = ListNode(l2.val)
            l2 = l2.next
            
        cur = head
        while(l1 is not None and l2 is not None):
            if l1.val < l2.val:
                cur.next = ListNode(l1.val)
                l1 = l1.next
            else:
                cur.next = ListNode(l2.val)
                l2 = l2.next
            cur = cur.next
            
        while(l1 is not None):
            cur.next = ListNode(l1.val)
            l1 = l1.next
            cur = cur.next
            
        while(l2 is not None):
            cur.next = ListNode(l2.val)
            l2 = l2.next
            cur = cur.next
            
        return head