class Solution:
    """
    https://leetcode.com/problems/palindromic-substrings/
    """
    def countSubstrings(self, s: str) -> int:
        if len(s) == 1:
            return 1
        n = len(s)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        count = 0
        for i in range(n):
            #each character is a palindrome by default
            dp[i][i] = 1
            count += 1
        
        
        for i in range(n-1):
            #for 2 characters
            if s[i] == s[i+1]:
                dp[i][i+1] = 1
                count+=1
                
        for k in range(3, n+1):
            for i in range(n - k + 1):
                start = i
                end = i + k - 1
                if s[start] == s[end]:
                    if dp[start + 1][end - 1] == 1:
                        dp[start][end] = 1
                        count+=1
                
        return count