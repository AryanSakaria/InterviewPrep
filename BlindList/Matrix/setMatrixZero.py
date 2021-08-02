# https://leetcode.com/problems/set-matrix-zeroes/
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row_z, col_z = [], []
        m, n = len(matrix), len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row_z.append(i)
                    col_z.append(j)
                    
        for i in range(m):
            for j in range(n):
                if i in row_z or j in col_z:
                    matrix[i][j] = 0