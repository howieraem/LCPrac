// import java.util.*;
/*
 * @lc app=leetcode.cn id=1218 lang=java
 *
 * [1218] 最长定差子序列
 */

// @lc code=start
class Solution {
    public int longestSubsequence(int[] arr, int difference) {
        // Map<Integer, Integer> dp = new HashMap<>();

        // Given -1e4 <= arr[i], difference <= 1e4, the range of possible values is [-2e4, 2e4].
        // Instead of a hash map, an integer array is sufficient to store all the states.
        final int offset = 20000;
        int[] dp = new int[2 * offset + 1];

        int ans = 1;
        for (int x : arr) {
            // dp.put(x, dp.getOrDefault(x - difference, 0) + 1);
            // ans = Math.max(ans, dp.get(x));
            ans = Math.max(ans, dp[x + offset] = dp[(x - difference) + offset] + 1);
        }
        return ans;
    }
}
// @lc code=end

