/*
 * @lc app=leetcode.cn id=36 lang=java
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
    public boolean isValidSudoku(char[][] board) {
        int[][] rowFreq = new int[9][9];
        int[][] colFreq = new int[9][9];
        int[][] subboxFreq = new int[9][9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.')  continue;
                int idx = c - '0' - 1;
                int k = 3 * (i / 3) + j / 3;
                ++rowFreq[i][idx];
                ++colFreq[j][idx];
                ++subboxFreq[k][idx];
                if (rowFreq[i][idx] > 1 || colFreq[j][idx] > 1 || subboxFreq[k][idx] > 1)
                    return false;
            }
        }
        return true;
    }
}
// @lc code=end

