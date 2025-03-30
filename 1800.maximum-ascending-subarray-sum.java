/*
 * @lc app=leetcode id=1800 lang=java
 *
 * [1800] Maximum Ascending Subarray Sum
 */

// @lc code=start
class Solution {
    // 1D DP, variant of Kadane's algo?
    // T: O(n)
    // S: O(1)
    public int maxAscendingSum(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int curSum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                // continue building the existing subarray
                curSum += nums[i];
            } else {
                // start a new subarray
                curSum = nums[i];
            }
            ans = Math.max(ans, curSum);
        }
        return ans;
    }
}
// @lc code=end

