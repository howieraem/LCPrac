/*
 * @lc app=leetcode.cn id=70 lang=java
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
    public int climbStairs(int n) {
        // int[] dp = new int[n + 1];
        // dp[0] = dp[1] = 1;
        // for (int i = 2; i <= n; ++i) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];

        int dp_i_2 = 1, dp_i_1 = 1, dp_i = 1; 
        for (int i = 2; i <= n; ++i) {
            dp_i = dp_i_2 + dp_i_1;
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
}
// @lc code=end

