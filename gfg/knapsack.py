#User function Template for python3

class Solution:
    """
    https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
    """
    
    #Function to return max value that can be put in knapsack of capacity W.
    def knapSack(self,W, wt, val, n):
        DP = [[0 for _ in range(W+1)] for _ in range(n+1)]
        # zipped = 
        for i in range(1, n+1):
            for j in range(1, W+1):
                if wt[i-1] <= j:
                    DP[i][j] = max(val[i-1] + DP[i-1][j-wt[i-1]], DP[i-1][j])
                else:
                    DP[i][j] = DP[i-1][j]
        
        return DP[-1][-1]
 
 
       
        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())
        W = int(input())
        val = list(map(int,input().strip().split()))
        wt = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.knapSack(W,wt,val,n))
# } Driver Code Ends