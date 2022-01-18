/*
 * @lc app=leetcode.cn id=115 lang=java
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
    public int numDistinct(String s, String t) {
        if (s == null)  return 0;
        if (t == null || t.length() == 0)  return s.length();
        int m = s.length(), n = t.length();
        if (n > m)  return 0;
        /* dp[i][j] meaning no. of distinct subsequences for s[:i] and t[:j] */
        int[][] dp = new int[m+1][n+1];
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i-1][j] + (s.charAt(i-1) == t.charAt(j-1) ? dp[i-1][j-1] : 0);
            }
        }
        return dp[m][n];
    }
}
// @lc code=end

