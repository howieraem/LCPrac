/*
 * @lc app=leetcode.cn id=416 lang=java
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
    public boolean canPartition(int[] nums) {
        if (nums.length == 0)  return false;
        int sum = 0;
        for (int num : nums)  sum += num;
        if (sum % 2 == 1)  return false;
        
        sum /= 2;
        boolean[] dp = new boolean[sum + 1];
        dp[0] = true;
        for (int i = 0; i < nums.length; ++i) {
            for (int j = sum; j >= 0; --j) {
                // j iterates from sum / 2 to 0 because every nums[i] can be used at most once
                // in a bag with volume sum / 2. Iterating from 0 to sum / 2 will cause bad
                // results with larger j.
                if (j >= nums[i])  dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
}
// @lc code=end

