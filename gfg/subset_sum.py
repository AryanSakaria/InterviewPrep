class Solution:
    """
    https://leetcode.com/problems/partition-equal-subset-sum/
    """
    def subset_sum_dp(self, nums, subset_num):
        DP = [[False for _ in range(subset_num+1)] for _ in range(len(nums))]
        
        for i in range(len(nums)):
            DP[i][0] = True
            
        for i in range(len(nums)):
            for j in range(1, subset_num+1):
                DP[i][j] = DP[i-1][j]
                if j - nums[i] >= 0:
                    DP[i][j] = DP[i][j] | DP[i-1][j - nums[i]]
                    
        return DP[-1][-1]
    
    def canPartition(self, nums: List[int]) -> bool:
        if len(nums) < 2:
            return False
        
        sum_tot = sum(nums)
        if sum_tot % 2 != 0:
            return False
        
        subset_sum = sum_tot // 2
        return self.subset_sum_dp(nums, subset_sum)