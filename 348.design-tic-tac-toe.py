#
# @lc app=leetcode id=348 lang=python3
#
# [348] Design Tic-Tac-Toe
#

# @lc code=start
class TicTacToe:
    # T: O(n)
    # S: O(n)
    def __init__(self, n: int):
        # possible values: [-n, n]
        self.rows = [0] * n
        self.cols = [0] * n
        self.diag = 0
        self.anti_diag = 0
        self.n = n

    # T: O(1)
    # S: O(1)
    def move(self, row: int, col: int, player: int) -> int:
        # if an n is achieved, player 2 wins
        # if a -n is achieved, player 1 wins
        offset = (player << 1) - 3   # player 1 -> offset -1, player 2 -> offset 1
        self.rows[row] += offset
        self.cols[col] += offset
        if row == col:
            self.diag += offset
        if row + col == self.n - 1:
            self.anti_diag += offset

        win_val = offset * self.n
        if win_val == self.rows[row] or \
            win_val == self.cols[col] or \
            win_val == self.diag or \
            win_val == self.anti_diag:
            # offset 1 -> player 2, offset -1 -> player 1
            return player
        return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
# @lc code=end

