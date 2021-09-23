import java.util.*;
/*
 * @lc app=leetcode id=1027 lang=java
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
    // More general case of Q1218.
    public int longestArithSeqLength(int[] nums) {
        int ans = 2;
        final int n = nums.length;
        Map<Integer, Integer>[] dp = new HashMap[n];

        for (int i = 0; i < n; ++i) {
            dp[i] = new HashMap<>();
            for (int j = 0; j < i; ++j) {
                int d = nums[i] - nums[j];
                int curLength = dp[j].getOrDefault(d, 1) + 1;
                dp[i].put(d, curLength);
                ans = Math.max(ans, curLength);
            }
        }
        return ans;
    }
}
// @lc code=end

