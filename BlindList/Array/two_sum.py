class Solution:
    """
    https://leetcode.com/problems/two-sum/
    """
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_table = {}
        for i, num in enumerate(nums):
            hash_table[num] = i
            
        for i, num in enumerate(nums):
            key = target - num
            target_idx = hash_table.get(key)
            if (target_idx is not None) and target_idx != i:
                return [i, target_idx]
        