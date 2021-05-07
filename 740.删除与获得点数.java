/*
 * @lc app=leetcode.cn id=740 lang=java
 *
 * [740] 删除与获得点数
 */

// @lc code=start
class Solution {
    public int deleteAndEarn(int[] nums) {
        int max = nums[0];
        for (int num : nums) {
            max = Math.max(max, num);
        }

        int[] cnt = new int[max + 1];
        for (int num : nums) {
            ++cnt[num];
        }

        int[] dp = new int[max + 1];
        dp[1] = cnt[1];
        for (int i = 2; i <= max; ++i) {
            // 与打家劫舍问题类似
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + i * cnt[i]);
        }
        return dp[max];
    }
}
// @lc code=end

