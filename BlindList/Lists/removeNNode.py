#https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next is None:
            return None
        i = 0
        n_pointer = head
        while (i < n):
            n_pointer = n_pointer.next
            i+=1

        dummy_head = head
        prev = head
        while(n_pointer is not None):
            n_pointer = n_pointer.next
            prev = dummy_head
            dummy_head = dummy_head.next

        prev.next = dummy_head.next
        if prev == dummy_head:
            head = head.next
        return head
