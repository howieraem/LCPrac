/*
 * @lc app=leetcode.cn id=62 lang=java
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
    // 2D DP
    // T: O(m * n)
    // S: O(n) after state compression
    public int uniquePaths(int m, int n) {
        // int[][] dp = new int[m][n];
        // dp[0][0] = 1;
        // for (int i = 1; i < m; i++) dp[i][0] = 1;
        // for (int j = 1; j < n; j++) dp[0][j] = 1;
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }
        // return dp[m - 1][n - 1];

        // Optimized version: Only need to store the previous row/col, so states can be compressed.
        // See https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/ 
        // for explanations.
        int[] dp = new int[n];
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
}
// @lc code=end

