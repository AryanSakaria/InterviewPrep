#https://leetcode.com/problems/word-search/
class Solution:
    def dfs_helper(self, board, word, i, j):
        if len(word) == 1:
            return True
        #Save the value. Do computation
        temp_store = board[i][j]
        board[i][j] = "#"
        found_bool = False
        for pair in self.directions:
            x,y = i+pair[0], j + pair[1]
            if x < 0 or y < 0 or x >= self.m or y >=self.n:
                continue
            if board[x][y] == word[1]:
                found_bool = self.dfs_helper(board, word[1:], x, y) or found_bool
        #restore
        board[i][j] = temp_store
        return found_bool

    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        self.m = m
        self.n = n

        self.directions = [(0,1), (1,0), (0,-1), (-1,0)]
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    if self.dfs_helper(board, word, i, j):
                        return True

        return False
