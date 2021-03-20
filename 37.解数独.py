#
# @lc app=leetcode.cn id=37 lang=python3
#
# [37] 解数独
#

# @lc code=start
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = [[False]*9 for _ in range(9)]
        col = [[False]*9 for _ in range(9)]
        subgrid = [[False]*9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                idx = int(board[i][j]) - 1
                k = (i // 3) * 3 + j // 3
                row[i][idx] = col[j][idx] = subgrid[k][idx] = True  # meaning the number already exists

        def solve(n):
            """helper func"""
            # represent row and col indices with one number from 0 to 9*9-1
            if n == 81:
                return True
            i, j = divmod(n, 9)
            if board[i][j] != '.':
                return solve(n+1)
            k = (i // 3) * 3 + j // 3
            for num in range(0, 9):
                if row[i][num] or col[j][num] or subgrid[k][num]:
                    # if number already exists, skip
                    continue
                board[i][j] = str(num+1)
                row[i][num] = col[j][num] = subgrid[k][num] = True
                if solve(n+1):
                    return True
                # failed to find solution for current number at current step,
                # trim branch
                row[i][num] = col[j][num] = subgrid[k][num] = False
            board[i][j] = '.'
            return False
        
        solve(0)

            


# @lc code=end

