# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    """
    https://leetcode.com/problems/binary-tree-maximum-path-sum/
    """
    def helper(self, root: Optional[TreeNode]) -> int:
        if root.left is None and root.right is None:
            return root.val, root.val
        
        if root.left is None and not root.right is None:
            maxSumRight, root_sumRight = self.helper(root.right)
            maxSum = max(maxSumRight, root.val, root_sumRight + root.val)
            rootRight = max(root.val, root.val + root_sumRight)
            return maxSum, rootRight
        
        if root.right is None and not root.left is None:
            maxSumLeft, root_sumLeft = self.helper(root.left)
            maxSum = max(maxSumLeft, root.val, root_sumLeft + root.val)
            rootLeft = max(root.val, root.val + root_sumLeft)
            return maxSum, rootLeft
        
        maxSumRight, root_sumRight = self.helper(root.right)
        maxSumLeft, root_sumLeft = self.helper(root.left)
        maxSum = max(maxSumRight, 
                     maxSumLeft, 
                     root.val, 
                    root.val + root_sumRight,
                    root.val + root_sumLeft,
                    root.val + root_sumRight + root_sumLeft)
        rootsum = max(root.val, root.val + root_sumRight, root.val + root_sumLeft)
        return maxSum, rootsum
        
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum, root_sum = self.helper(root)
        return maxSum