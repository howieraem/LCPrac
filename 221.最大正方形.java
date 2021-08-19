/*
 * @lc app=leetcode.cn id=221 lang=java
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length, cols = matrix[0].length;
        int maxLength = 0;
        
        // dp[i][j] means the maximum square side length for matrix[:i, :j]
        int[][] dp = new int[rows][cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // At left or top boundary, side length of a square can only be one
                        dp[i][j] = 1;
                    } else {
                        // Otherwise, current side length is subject to three adjacent matrix entries.
                        // Since it is square, need to pick the minimum of the three states.
                        dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                    maxLength = Math.max(maxLength, dp[i][j]);
                }
            }
        }
        return maxLength * maxLength;
    }
}
// @lc code=end

