class Solution:
    """
    https://leetcode.com/problems/maximum-subarray
    """
    def maxSubArray(self, nums: List[int]) -> int:
        sum_so_far = nums[0]
        best_sum = nums[0]
        for i, num in enumerate(nums[1:]):
            sum_so_far = max(num, sum_so_far + num)
            best_sum = max(best_sum, sum_so_far)       
        return best_sum