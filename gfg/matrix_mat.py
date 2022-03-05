#User function Template for python3
class Solution:
    def matrixMultiplication(self, N, arr):
        # code here
        n_len = N - 1 
        DP = [[0 for _ in range(n_len)] for _ in range(n_len)]
        for g in range(n_len):
            for j in range(g, n_len):
                i = j - g 
                # print("for i, j", i, j)
                if g == 0:
                    DP[i][j] = 0

                elif g == 1:
                    # print(i, j, k)
                    # print("i, j, g", i, j , g)
                    DP[i][j] = arr[i]*arr[i+1]*arr[i+2]
                    # print("DP[i][j]", DP[i][j], arr[i],arr[i+1], arr[i+2])

                else:
                    cur_val = -1
                    for k in range(i, j):
                #         print(i, j, k)
                        #cost of mult i to k-1 + k to j + (i-1 * k* j)
                        val = DP[i][k]  + DP[k+1][j] +  arr[i] * arr[k+1] * arr[j+1]
                        # print("i, j, k", i, j, k, val, DP[i][k], DP[k+1][j], arr[i], arr[k+1], arr[j+1])
                        # print(val)
                        if cur_val == -1:
                            cur_val = val 
                        else:
                            cur_val = min(cur_val, val)

                    DP[i][j] = cur_val
#         print(DP)
        return DP[0][n_len-1]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for i in range(N):
            arr[i] = int(arr[i])
        
        ob = Solution()
        print(ob.matrixMultiplication(N, arr))
# } Driver Code Ends