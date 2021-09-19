class Solution:
    """
    https://leetcode.com/problems/longest-palindromic-substring/
    """
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1:
            return s
        n = len(s)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        
        for i in range(n):
            #each character is a palindrome by default
            dp[i][i] = 1
            max_string = s[i]
            max_start = i
            max_end = i
        
        max_len = 1
        for i in range(n-1):
            #for 2 characters
            if s[i] == s[i+1]:
                max_len = 2
                dp[i][i+1] = 1
                max_start = i
                max_end = i + 1
                # max_string = s[i:i+2]
        for k in range(3, n+1):
            for i in range(n - k + 1):
                start = i
                end = i + k - 1
                if s[start] == s[end]:
                    if dp[start + 1][end - 1] == 1:
                        dp[start][end] = 1
                        if (end - start + 1) > max_len:
                            max_len = (end - start + 1)
                            max_start = start
                            max_end = end
                            # max_string = s[start:end + 1]
                    
                # dp[i][i + k - 1]
                
        max_string = s[max_start:max_end + 1]
        return max_string