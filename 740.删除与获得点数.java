/*
 * @lc app=leetcode.cn id=740 lang=java
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
    public int deleteAndEarn(int[] nums) {
        int max = nums[0];
        /* nums[i] <= 1e4 */
        // int[] cnt = new int[10001];
        int[] trans = new int[10001];
        for (int num : nums) {
            // ++cnt[num];
            trans[num] += num;
            max = Math.max(max, num);
        }

        // int[] dp = new int[max + 1];
        // dp[1] = cnt[1];
        int dp_i_2 = 0, dp_i_1 = trans[1];
        for (int i = 2; i <= max; ++i) {
            // Similar to Q198, rob either the current one or the next one
            // dp[i] = Math.max(dp[i - 1], dp[i - 2] + i * cnt[i]);
            int pre = dp_i_1;
            dp_i_1 = Math.max(dp_i_1, dp_i_2 + trans[i]);
            dp_i_2 = pre;
        }
        // return dp[max];
        return dp_i_1;
    }
}
// @lc code=end

