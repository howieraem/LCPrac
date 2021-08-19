/*
 * @lc app=leetcode.cn id=63 lang=java
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid[0][0] == 1)  return 0;
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1)  continue;
                if (i > 0 || j > 0) {
                    int left = i == 0 ? 0 : dp[i - 1][j];
                    int top = j == 0 ? 0 : dp[i][j - 1];
                    dp[i][j] = left + top;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
}
// @lc code=end

