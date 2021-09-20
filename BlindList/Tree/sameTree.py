# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    https://leetcode.com/problems/same-tree/
    """
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if p is None and not q is None:
            return False
        if q is None and not p is None:
            return False
        if p is None and q is None:
            return True
        
        if not p.val == q.val:
            return False
        
        check_flag_left = self.isSameTree(p.left, q.left)
        check_flag_right = self.isSameTree(p.right, q.right)
        return check_flag_left and check_flag_right