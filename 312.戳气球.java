/*
 * @lc app=leetcode.cn id=312 lang=java
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] coins = new int[n + 2];
        coins[0] = coins[n + 1] = 1;
        for (int i = 0; i < n; ++i) {
            coins[i + 1] = nums[i];
        }

        // dp[i][j] means the maximum no. of coins obtained if 
        // balloons with indices in (i, j) are all popped.
        // Therefore, dp[0][n+1] is the final answer.
        int[][] dp = new int[n + 2][n + 2];

        for (int i = n; i >= 0; --i) {
            for (int j = i + 1; j <= n + 1; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    // k stands for the index of last balloon popped
                    dp[i][j] = Math.max(
                        dp[i][j],
                        dp[i][k] + dp[k][j] + coins[i] * coins[k] * coins[j]
                    );
                    // Since the final answer is dp[0][n+1], and dp[i][j] depends on 
                    // dp[i][k] and dp[k][j], iterate i from n to 0 and iterate j
                    // from i + 1 to n + 1. i does not begin at n + 1 because j
                    // must begin at i + 1 such as there is at least one balloon
                    // between balloons i and j.
                }
            }
        }
        return dp[0][n + 1];
    }
}
// @lc code=end

