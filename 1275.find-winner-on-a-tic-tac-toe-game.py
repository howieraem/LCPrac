#
# @lc app=leetcode id=1275 lang=python3
#
# [1275] Find Winner on a Tic Tac Toe Game
#
from typing import List

# @lc code=start
class Solution:
    # T: O(len(moves))
    # S: O(N), N := 3
    def tictactoe(self, moves: List[List[int]]) -> str:
        N = 3
        row = [0] * N
        col = [0] * N
        diag = 0
        antidiag = 0
        turn = 1  # 1 for A and -1 for B

        for [r, c] in moves:
            row[r] += turn
            col[c] += turn
            diag += turn * (r == c)
            antidiag += turn * (r + c == N - 1)
            if abs(row[r]) == N or abs(col[c]) == N or abs(diag) == N or abs(antidiag) == N:
                return "A" if turn == 1 else "B"
            turn *= -1
        return "Pending" if len(moves) < N * N else "Draw"

# @lc code=end

