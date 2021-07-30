# https://leetcode.com/problems/reverse-linked-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        prev = None
        
        while(head.next is not None):
            next_node = head.next
            head.next = prev
            prev = head
            head = next_node
            
        head.next = prev
        return head