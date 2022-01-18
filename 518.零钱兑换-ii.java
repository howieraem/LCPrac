/*
 * @lc app=leetcode.cn id=518 lang=java
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
    public int change(int amount, int[] coins) {
        // time O(N*amount), space O(amount)
        int[] dp = new int[amount + 1];
        dp[0] = 1;

        // 完全背包，即数组中的元素可重复使用
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
}
// @lc code=end

