import java.util.*;

/*
 * @lc app=leetcode.cn id=377 lang=java
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
    // 背包问题：能否使用nums中的元素做各种排列组合得到target
    public int combinationSum4(int[] nums, int target) {
        if (nums.length == 0)  return 0;
        int[] dp = new int[target + 1];
        dp[0] = 1;  // base case

        // num in nums can be used multiple times
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];   // 组合类背包问题公式
                }
            }
        }
        return dp[target];
    }
}
// @lc code=end

