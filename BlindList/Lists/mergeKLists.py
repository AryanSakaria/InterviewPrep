# https://leetcode.com/problems/merge-k-sorted-lists/submissions/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        ListNode.__lt__ = lambda self, other: self.val < other.val
        q = PriorityQueue()
        for head in lists:
            if head is not None:
                val = head.val
                q.put((val, head))
                
        head = tail = None
        while(not q.empty()):
            (val, node) = q.get()
            # print(val)
            node = node.next
            if head == None:
                head = ListNode(val)
                tail = head
            else:
                tail.next = ListNode(val)
                tail = tail.next
            if node is not None:
                q.put((node.val, node))
                
        return head