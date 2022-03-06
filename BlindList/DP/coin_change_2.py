class Solution:
	"""
	https://leetcode.com/problems/coin-change-2/submissions/
	"""
    def change(self, amount: int, coins: List[int]) -> int:
        DP = [0 for _ in range(amount+1)]
        DP[0] = 1
        for c in coins:
            for i in range(amount+1):
                if i - c >= 0:
                    print(i, c)
                    DP[i] += DP[i-c]
                 
        # print(DP)
        return DP[-1]