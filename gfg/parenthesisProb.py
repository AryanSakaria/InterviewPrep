#User function Template for python3

class Solution:
    """
    https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
    """
    def countWays(self, N, S):
        count = 0
        sym = []
        op = []
        for i in S:
            if count % 2 == 0:
                sym.append(i)
            else:
                op.append(i)

            count += 1
        True_dp = [[0 for _ in range(len(sym))] for _ in range(len(sym))]
        False_dp = [[0 for _ in range(len(sym))] for _ in range(len(sym))]
        
        for g in range(0, len(sym)):
            for j in range(g, len(sym)):
                i = j - g 

                if g == 0:
                    if sym[i] == 'T':
                        True_dp[i][j] = 1
                        False_dp[i][j] = 0
                    else:
                        False_dp[i][j] = 1
                        True_dp[i][j] = 0 
                else:
                    true_val = 0
                    false_val = 0
                    for k in range(i,j):
                        if op[k] == '&':
                            true_val += True_dp[i][k] * True_dp[k+1][j]
                            false_val += (True_dp[i][k] + False_dp[i][k])*(True_dp[k+1][j] + False_dp[k+1][j]) - True_dp[i][k]*True_dp[k+1][j]

                        if op[k] == '|':
                            true_val += (True_dp[i][k] + False_dp[i][k])*(True_dp[k+1][j] + False_dp[k+1][j]) - False_dp[i][k]*False_dp[k+1][j]
                            false_val += False_dp[i][k] * False_dp[k+1][j]

                        if op[k] == '^':
                            true_val += True_dp[i][k]*False_dp[k+1][j] + False_dp[i][k]*True_dp[k+1][j]
                            false_val += True_dp[i][k]*True_dp[k+1][j] + False_dp[i][k]*False_dp[k+1][j]

                    True_dp[i][j] = true_val%1003
                    False_dp[i][j] = false_val%1003

        return True_dp[0][-1]



        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        S = input()
        
        ob = Solution()
        print(ob.countWays(N, S))
# } Driver Code Ends