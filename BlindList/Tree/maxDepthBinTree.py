# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    https://leetcode.com/problems/maximum-depth-of-binary-tree/
    """
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        max_depth_left = self.maxDepth(root.left)
        max_depth_right = self.maxDepth(root.right)
        return 1 + max(max_depth_left, max_depth_right)
        