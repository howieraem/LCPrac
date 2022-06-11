/*
 * @lc app=leetcode.cn id=322 lang=java
 *
 * [322] 零钱兑换
 */
import java.util.*;

// @lc code=start
class Solution {
    /* // 背包，自上而下
    public int coinChange(int[] coins, int amount) {
        // if (coins.length == 0)  return -1;
        int[] dp = new int[amount+1];
        Arrays.fill(dp, amount+1);
        dp[0] = 0;
        for (int i = 0; i < amount+1; ++i) {
            for (int coin : coins) {
                if (i < coin)  continue;
                dp[i] = Math.min(dp[i], dp[i-coin] + 1);
            }
        }
        if (dp[amount] == amount+1)  return -1;
        return dp[amount];
    }
    */

    // 背包，自下而上
    public int coinChange(int[] coins, int amount) {
        // if (coins.length == 0)  return -1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, 1, amount + 1, Integer.MAX_VALUE);  // keep dp[0] = 0
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        /*
        for (int i = 1; i <= amount; ++i) {
            dp[i] = Integer.MAX_VALUE;  // keep dp[0] = 0
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        */
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }
}
// @lc code=end

