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

    // 2D DP (generalized to any number of allowable transactions, same as Q188)
    // T: O(n * k), k := no. of allowable transactions
    // S: O(k) state compression
    public int maxProfit(int[] prices) {
        int[] dp_buy = new int[K];
        Arrays.fill(dp_buy, Integer.MIN_VALUE);
        int[] dp_sell = new int[K];

        for (int i = 0; i < prices.length; ++i) {
            dp_buy[0] = Math.max(dp_buy[0], -prices[i]);
            dp_sell[0] = Math.max(dp_sell[0], dp_buy[0] + prices[i]);
            for (int j = 1; j < K; ++j) {
                dp_buy[j] = Math.max(dp_buy[j], dp_sell[j - 1] - prices[i]);  // can buy only after the last sell
                dp_sell[j] = Math.max(dp_sell[j], dp_buy[j] + prices[i]);
            }
        }
        return dp_sell[K - 1];
    }
}
// @lc code=end

