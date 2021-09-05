/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        final int n = nums.length;

        // dp[i] means maximum sum of the subarrays that ends at nums[i]
        // int[] dp = new int[n];  
        // dp[0] = nums[0];
        // int ans = dp[0];

        // State compressed
        int dp = nums[0], ans = nums[0];

        for (int i = 1; i < n; ++i) {
            // Whether to include the current number in the subarray,
            // or make a new subarray.
            // ans = Math.max(ans, dp[i] = Math.max(dp[i - 1] + nums[i], nums[i]));
            ans = Math.max(ans, dp = Math.max(dp + nums[i], nums[i]));
        }
        return ans;
    }
}
// @lc code=end

