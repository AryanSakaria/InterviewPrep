class Solution:
    """
    https://leetcode.com/problems/container-with-most-water/
    """
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        answer = 0
        while l <=r :
            cur_area = (r - l)*min(height[r], height[l])
            answer = max(answer, cur_area)
            if height[l] < height[r]:
                l+=1
            else:
                r-=1
        return answer