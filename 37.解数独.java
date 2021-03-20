/*
 * @lc app=leetcode.cn id=37 lang=java
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
    private static final int M = 9, N = 9;

    public void solveSudoku(char[][] board) {
        backtrack(board, 0, 0);
    }

    private boolean backtrack(char[][] board, int i, int j) {
        if (j == N) {
            // move to first column of the next row
            return backtrack(board, i + 1, 0);
        }
        if (i == M)  return true;  // solved
        if (board[i][j] != '.')  {
            // skip cells already filled with a number
            return backtrack(board, i, j + 1);
        }
        for (char ch = '1'; ch <= '9'; ++ch) {
            if (!isValid(board, i, j, ch))  continue;
            board[i][j] = ch;    // try setting value
            if (backtrack(board, i, j + 1)) {
                // enumerate next column and check if problem already solved
                return true;
            }
            board[i][j] = '.';   // undo
        }
        return false;   // no solution found in this track
    }

    private boolean isValid(char[][] board, int r, int c, char n) {
        // Checks whether n already exists in current row, column or 3 * 3 block.
        // Returns false if exists.
        for (int i = 0; i < 9; ++i) {
            if (
                board[r][i] == n ||     // row
                board[i][c] == n ||     // col
                board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == n    // block
            )
                return false;
        }
        return true;
    }
}
// @lc code=end

