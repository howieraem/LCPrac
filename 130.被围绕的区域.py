#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#

# @lc code=start
class Solution:
    """
    Actual Problem: find all "O"s connected to the border.

    Trick: use an auxiliary symbol "#" to mark a visited "O". 
    """
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        h, w = len(board), len(board[0])

        def dfs(board, i, j):
            if (
                i < 0 or
                j < 0 or
                i >= h or
                j >= w or 
                board[i][j] == 'X' or
                board[i][j] == '#'
            ):
                return
            # if board[i][j] == 'O':
            board[i][j] = '#'
            dfs(board, i-1, j)
            dfs(board, i+1, j)
            dfs(board, i, j-1)
            dfs(board, i, j+1)

        for i in range(h):
            for j in range(w):
                if (not i or not j or i == h-1 or j == w-1) and board[i][j] == 'O':
                    dfs(board, i, j)

        for i in range(h):
            for j in range(w):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == '#':
                    board[i][j] = 'O'


# @lc code=end

