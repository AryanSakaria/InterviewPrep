class Solution:
    """
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock
    """
    def maxProfit(self, prices: List[int]) -> int:
        min_so_far = 100000
        target = 0
        for price in prices:
            min_so_far = min(min_so_far, price)
            target = max(target, price - min_so_far)
        return target