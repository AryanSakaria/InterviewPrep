class Solution:
    """
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
    """
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        if nums[l] < nums[r]:
            return nums[l]
        
        while(l <= r):
            mid = l + (r-l)//2
            
            if nums[mid] < nums[mid-1]:
                return nums[mid]
            
            if nums[mid] < nums[r]:
                r = mid - 1
            else:
                l = mid + 1
        return nums[r]