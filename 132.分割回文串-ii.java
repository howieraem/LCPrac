import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=132 lang=java
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    public int minCut(String s) {
        final int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int[] dp_min_cnts = new int[n];

        for (int r = 0; r < n; ++r) {
            int tmp = Integer.MAX_VALUE;
            for (int l = 0; l <= r; ++l) {
                if (s.charAt(r) == s.charAt(l) && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                    tmp = l > 0 ? Math.min(tmp, dp_min_cnts[l - 1] + 1) : 0;
                }
            }
            dp_min_cnts[r] = tmp;
        }
        return dp_min_cnts[dp_min_cnts.length - 1];
    }
}
// @lc code=end

