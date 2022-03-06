#User function Template for python3

class Solution:
    
    #Function to find length of shortest common supersequence of two strings.
    def shortestCommonSupersequence(self, X, Y, m, n):
        DP = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                if X[i] == Y[j]:
                    DP[i+1][j+1] = DP[i][j] + 1
                else:
                    DP[i+1][j+1] = max(DP[i][j+1], DP[i+1][j])
        lcs = DP[-1][-1]
        answer = m + n - lcs
        return answer
        
         #code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        X,Y=input().split()
        
        print(Solution().shortestCommonSupersequence(X,Y,len(X),len(Y)))
        
# } Driver Code Ends