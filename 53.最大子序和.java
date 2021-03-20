/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        if (n == 0)  return 0;

        // dp[i] means maximum sum of the subarray that ends at nums[i]
        int[] dp = new int[n];  
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = Math.max(nums[i], dp[i - 1] + nums[i]);
        }

        // dp[-1] may not be the maximum.
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < dp.length; ++i) {
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
// @lc code=end

