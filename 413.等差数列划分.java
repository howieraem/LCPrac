/*
 * @lc app=leetcode.cn id=413 lang=java
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        // int[] dp = new int[n];  // dp[i] -> 以 nums[i] 为结尾的等差子数组数量
        int dp = 0;
        int ans = 0;

        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                // dp[i] = dp[i - 1] + 1;
                // ans += dp[i];
                ans += ++dp;
            } else {
                dp = 0;
            }
        }
        return ans;
    }
}
// @lc code=end
