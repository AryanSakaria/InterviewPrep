#User function Template for python3


#Function to find the maximum possible amount of money we can win.
"""
https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
"""
class Solution:
    def optimalStrategyOfGame(self,arr, n):
        # code here

        DP = [[0 for _ in range(n)] for _ in range(n)]
        for g in range(n):
            for j in range(g,n):
                i = j - g 
                if g == 0:
                    DP[i][j] = arr[i]
                elif g == 1:
                    DP[i][j] = max(arr[i], arr[j])
                else:
                    val1 = arr[i] + min(DP[i+2][j],DP[i+1][j-1])
                    val2 = arr[j] + min(DP[i+1][j-1],DP[i][j-2])
                    DP[i][j] = max(val1, val2)

        return DP[0][n-1]

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
        arr = list(map(int,input().strip().split()))
        ob = Solution()
        print(ob.optimalStrategyOfGame(arr,n))

# } Driver Code Ends