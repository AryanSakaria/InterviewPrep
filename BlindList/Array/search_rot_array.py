class Solution:
    """
    https://leetcode.com/problems/search-in-rotated-sorted-array
    """
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        if nums[l] < nums[r]:
            return l
        
        while(l <= r):
            mid = l + (r-l)//2
            
            if nums[mid] < nums[mid-1]:
                return mid
            
            if nums[mid] < nums[r]:
                r = mid - 1
            else:
                l = mid + 1
        return r
    
    def search(self, nums: List[int], target: int) -> int:
        k = self.findMin(nums)
        n = len(nums)
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + (r - l)//2
            if nums[(mid + k)%n] == target:
                return (mid + k)%n
            if nums[(mid + k)%n] < target:
                l = mid + 1
            else:
                r = mid - 1
                
        return -1