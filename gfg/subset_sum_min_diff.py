#User function Template for python3
class Solution:
    """
    https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
    """
    def get_DP(self, arr, k):
        DP = [[False for _ in range(k+1)] for _ in range(len(arr))]
        for i in range(len(arr)):
            DP[i][0] = True
            
        for i in range(len(arr)):
            for j in range(1,k+1):
                DP[i][j] = DP[i-1][j]
                if j - arr[i] >=0:
                    DP[i][j] = DP[i][j] | DP[i-1][j-arr[i]]
                    
        return DP
        
    def minDifference(self, arr, n):
        if n == 1:
            return arr[0]
            
        arr_sum = sum(arr)
        sub_sum = arr_sum//2
        DP = self.get_DP(arr,sub_sum)
        for i in range(sub_sum):
            if DP[-1][sub_sum-i]:
                break
       # print(i)
       # print(DP)
        s1 = sub_sum - i
        s2 = arr_sum - s1
        
        return abs(s2 - s1)
        # code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        N = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.minDifference(arr, N)
        print(ans)

# } Driver Code Ends