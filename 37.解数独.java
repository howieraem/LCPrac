/*
 * @lc app=leetcode.cn id=37 lang=java
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
    public final static int D = 9, DIGITS_NUM = 9, D_BLOCK = 3;

    public void solveSudoku(char[][] board) {
        boolean[][] seenR = new boolean[D][DIGITS_NUM], seenC = new boolean[D][DIGITS_NUM], seenB = new boolean[D][DIGITS_NUM];
        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    int digit = ch - '1', blockIdx = i / D_BLOCK * D_BLOCK + j / D_BLOCK;
                    seenR[i][digit] = seenC[j][digit] = seenB[blockIdx][digit] = true;
                }
            }
        }
        dfs(board, seenR, seenC, seenB, 0, 0);
    }

    private static boolean dfs(char[][] board, boolean[][] seenR, boolean[][] seenC, boolean[][] seenB, int i, int j) {
        if (j == D)  return true;
        if (board[i][j] == '.') {
            for (char ch = '1'; ch <= '9'; ++ch) {
                int digit = ch - '1', squareInd = i / D_BLOCK * D_BLOCK + j / D_BLOCK;
                if (!seenR[i][digit] && !seenC[j][digit] && !seenB[squareInd][digit]) {
                    seenR[i][digit] = seenC[j][digit] = seenB[squareInd][digit] = true;
                    if (dfs(board, seenR, seenC, seenB, (i + 1) % D, j + (i + 1) / D)) {
                        board[i][j] = ch;
                        return true;
                    }
                    seenR[i][digit] = seenC[j][digit] = seenB[squareInd][digit] = false;
                }
            }
            return false;
        }
        // Current cell is filled with a digit already, go to the next cell.
        return dfs(board, seenR, seenC, seenB, (i + 1) % D, j + (i + 1) / D);
    }

    /* Below is an old solution */
    // public void solveSudoku(char[][] board) {
    //     backtrack(board, 0, 0);
    // }

    // private boolean backtrack(char[][] board, int i, int j) {
    //     if (j == 9) {
    //         // move to first column of the next row
    //         return backtrack(board, i + 1, 0);
    //     }
    //     if (i == 9)  return true;  // solved
    //     if (board[i][j] != '.')  {
    //         // skip cells already filled with a number
    //         return backtrack(board, i, j + 1);
    //     }
    //     for (char ch = '1'; ch <= '9'; ++ch) {
    //         if (!isValid(board, i, j, ch))  continue;
    //         board[i][j] = ch;    // try setting value
    //         if (backtrack(board, i, j + 1)) {
    //             // enumerate next column and check if problem already solved
    //             return true;
    //         }
    //         board[i][j] = '.';   // undo
    //     }
    //     return false;   // no solution found in this track
    // }

    // private boolean isValid(char[][] board, int r, int c, char n) {
    //     // Checks whether n already exists in current row, column or 3 * 3 block.
    //     // Returns false if exists.
    //     for (int i = 0; i < 9; ++i) {
    //         if (
    //             board[r][i] == n ||     // row
    //             board[i][c] == n ||     // col
    //             board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == n    // block
    //         )
    //             return false;
    //     }
    //     return true;
    // }
}
// @lc code=end

