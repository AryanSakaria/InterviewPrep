class Solution:
    """
    https://leetcode.com/problems/maximum-product-subarray
    """
    def maxProduct(self, nums: List[int]) -> int:
        result = nums[0]
        cur_prod = 1
        
        for x in nums:
            cur_prod = cur_prod*x
            result = max(result, cur_prod)
            if cur_prod == 0:
                cur_prod = 1
        cur_prod = 1 
        for x in reversed(nums):
            cur_prod = cur_prod*x
            result = max(result, cur_prod)
            if cur_prod == 0:
                cur_prod = 1
                
        return result