# https://leetcode.com/problems/reorder-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def get_mid(self, head):
        tail = head
        n = 0
        while(tail is not None):
            n+=1
            tail = tail.next
            
        # print(n)
        mid = n//2
        mid_tail = head
        i = 0
        while(i < mid  + (n%2)):
            prev = mid_tail
            mid_tail = mid_tail.next
            i+=1
        # print(mid_tail.val)
        prev.next = None
        return mid_tail
        
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
    
    def join(self, head, mid):
        head_tracking = head
        
        while(head is not None and mid is not None):
            print(head.val)
            head_next = head.next
            head.next = mid
            head = head_next
            print(mid.val)
            if mid.next is None:
                mid_prev = mid
            mid_next = mid.next
            mid.next = head
            mid = mid_next
        if head is not None:
            mid_prev.next = head
            head.next = None
            
        return head_tracking
    
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None:
            return head
        
        mid_tail = self.get_mid(head)
        mid_tail = self.reverseList(mid_tail)
        head = self.join(head, mid_tail)