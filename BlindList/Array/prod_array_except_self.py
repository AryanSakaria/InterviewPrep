class Solution:
    """
    https://leetcode.com/problems/product-of-array-except-self/
    """
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if len(nums) == 2:
            nums.reverse()
            return nums
        prefix = [nums[0]]
        for num in nums[1:]:
            prefix.append(num*prefix[-1])
            
        nums.reverse()
        suffix = [nums[0]]
        for num in nums[1:]:
            suffix.append(num*suffix[-1])    
        suffix.reverse()
        
        answer = [0]*len(nums)
        answer[0] = suffix[1]
        answer[-1] = prefix[-2]
        
        for i in range(1,len(nums)-1):
            answer[i] = prefix[i-1]* suffix[i+1]
        
        return answer