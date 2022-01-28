/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    // public int maxProfit(int[] prices) {
    //     // 前 i 天的最大收益 = max(前 i-1 天的最大收益，第 i 天的价格 - 前 i-1 天中的最小价格)
    //     int ans = 0, min = prices[0];
    //     for (int i = 1; i < prices.length; ++i) {
    //         ans = Math.max(ans, prices[i] - min);
    //         min = Math.min(min, prices[i]);
    //     }
    //     return ans;
    // }

    // Made similar to Q53: do maxSubArray() on the array of interday price differences
    public int maxProfit(int[] prices) {
        int ans = 0, dp = 0;
        for (int i = 1; i < prices.length; ++i) {
            int diff = prices[i] - prices[i - 1];
            ans = Math.max(ans, dp = Math.max(dp + diff, diff));
        }
        return ans;
    }
}
// @lc code=end

