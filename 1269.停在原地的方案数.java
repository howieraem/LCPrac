/*
 * @lc app=leetcode.cn id=1269 lang=java
 *
 * [1269] 停在原地的方案数
 */

// @lc code=start
class Solution {
    private static final int MOD = 1000000007;

    public int numWays(int steps, int arrLen) {
        int maxLen = Math.min(arrLen - 1, steps / 2 + 1);

        // dp[i][j] 表示在 i 步操作之后，指针位于下标 j 的方案数
        int[][] dp = new int[steps + 1][maxLen + 1];
        dp[0][0] = 1;

        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j <= maxLen; ++j) {
                dp[i][j] = dp[i - 1][j];    // stay
                if (j - 1 >= 0) {
                    // 1 forward
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if (j + 1 <= maxLen) {
                    // 1 backward
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }
        return dp[steps][0];
    }
}
// @lc code=end

