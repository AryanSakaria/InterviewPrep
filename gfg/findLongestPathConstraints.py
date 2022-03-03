#User function Template for python3
"""
https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/
"""
class Solution:
    def explore(self, DP, mat, i, j, m, n):
        if DP[i][j]!=-1:
            return DP[i][j]
        else:
            #init as starting:
            DP[i][j] = 1
            directions = [(0,1),(0,-1),(1,0),(-1,0)]
            test_var = 0
            for x in directions:
                i_x = i + x[0]
                i_y = j + x[1]
                if i_x >= 0 and i_x < m and i_y >= 0 and i_y < n:
                    if mat[i_x][i_y] - mat[i][j] > 0:
                        test_var = max(test_var,self.explore(DP, mat, i_x, i_y, m,n))
        DP[i][j] += test_var
        return DP[i][j]
    
    def longestIncreasingPath(self, matrix):
        mat = matrix
        m, n = len(mat), len(mat[0])
        DP = [[-1 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                self.explore(DP, mat, i, j,m, n)
        answer = 0
        for i in DP:
            for j in i:
                answer = max(answer, j)
    
        return answer
        #Code here

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n); m = int(m);
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        obj = Solution()
        ans = obj.longestIncreasingPath(matrix)
        print(ans)

# } Driver Code Ends