/*
 * @lc app=leetcode.cn id=73 lang=java
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
    public void setZeroes(int[][] matrix) {
        boolean flagFirstCol = false;
        int r = matrix.length, c = matrix[0].length;
        for (int i = 0; i < r; ++i) {
            if (matrix[i][0] == 0) {
                flagFirstCol = true;
            }
            for (int j = 1; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    // using the first row and the first column as flags 
                    // to set internal rows and columns later, while
                    // noting whether originally the first row or first
                    // column has zero with `flagFirstCol`
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = r - 1; i >= 0; --i) {
            for (int j = c - 1; j > 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (flagFirstCol) { 
                matrix[i][0] = 0;
            }
        }
    }
}
// @lc code=end

