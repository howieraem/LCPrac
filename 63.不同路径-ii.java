/*
 * @lc app=leetcode.cn id=63 lang=java
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
    // 2D DP
    // T: O(m * n)
    // S: O(m) after state compression
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length; 
        if (m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].length;
        if (n == 0 || obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        /*
        // 2D DP array
        int[][] dp = new int[m][n];
        dp[0][0] = 1;

        // Top and left edges
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            } 
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            dp[0][j] = 1;
        }
        
        // All other cells
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
        */

        // State compression
        int[] dp = new int[m];

        // init base cases for first column / left edge
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i] = 1;
        }

        for (int j = 1; j < n; ++j) {
            boolean viable = false;

            // init base cases for first row / top edge
            if (obstacleGrid[0][j] == 1) {
                dp[0] = 0;
            } else {
                viable = true;
            }
            
            // other cells of current column
            for (int i = 1; i < m; ++i) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i] += dp[i - 1];
                    if (dp[i] > 0) {
                        viable = true;
                    }
                } else {
                    dp[i] = 0;
                }
            }

            if (!viable) {
                return 0;
            }
        }
        return dp[m - 1];
    }
}
// @lc code=end

