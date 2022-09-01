#
# @lc app=leetcode id=419 lang=python3
#
# [419] Battleships in a Board
#
from typing import List

# @lc code=start
class Solution:
    # T: O(m * n)
    # S: O(1)
    def countBattleships(self, board: List[List[str]]) -> int:
        m = len(board)
        n = len(board[0])
        ans = 0

        # Only works if there are no adjacent battleships
        for i in range(m):
            for j in range(n):
                ans += not (
                    # not a battleship
                    board[i][j] == '.' or
                    # skip if previous row/col is of the same battleship
                    (i > 0 and board[i - 1][j] == 'X') or
                    (j > 0 and board[i][j - 1] == 'X')
                )
        return ans

# @lc code=end

