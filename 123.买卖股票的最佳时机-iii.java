import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=123 lang=java
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
    private static final int K = 2;

    // public int maxProfit(int[] prices) {
    //     int n = prices.length;

    //     // dp[i][j][0] means balance after selling,
    //     // dp[i][j][1] means balance after buying.
    //     int[][][] dp = new int[n][K + 1][2];

    //     for (int i = 0; i < n; ++i)  dp[i][0][1] = Integer.MIN_VALUE;
    //     for (int j = 1; j <= K; ++j)  dp[0][j][1] = -prices[0];

    //     for (int i = 1; i < n; ++i) {
    //         for (int j = 1; j <= K; ++j) {
    //             dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
    //             dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
    //         }
    //     }
    //     return dp[n - 1][K][0];
    // }

    public int maxProfit(int[] prices) {
        int[] buys = new int[K], sells = new int[K];
        Arrays.fill(buys, Integer.MIN_VALUE);

        for (int i = 0; i < prices.length; ++i) {
            buys[0] = Math.max(buys[0], -prices[i]);
            sells[0] = Math.max(sells[0], buys[0] + prices[i]);
            for (int j = 1; j < K; ++j) {
                buys[j] = Math.max(buys[j], sells[j - 1] - prices[i]);
                sells[j] = Math.max(sells[j], buys[j] + prices[i]);
            }
        }
        return sells[K - 1];
    }
}
// @lc code=end

