class Solution:
    """
    https://leetcode.com/problems/contains-duplicate/
    """
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_set = set(nums)
        if len(nums) != len(num_set):
            return True
        return False