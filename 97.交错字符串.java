/*
 * @lc app=leetcode.cn id=97 lang=java
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int x = s1.length(), y = s2.length(), z = s3.length();
        if (x + y != z)  return false;

        /* dp[i][j] means if s1[:i] and s2[:j] can form interleave s3[:i+j]. */
        // boolean[][] dp = new boolean[x+1][y+1];
        // dp[0][0] = true;
        boolean[] dp = new boolean[y+1];
        dp[0] = true;
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j <= y; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    // dp[i][j] |= (dp[i-1][j] && s1.charAt(i-1) == s3.charAt(k));
                    dp[j] = dp[j] && s1.charAt(i-1) == s3.charAt(k);
                }
                if (j > 0) {
                    // dp[i][j] |= (dp[i][j-1] && s2.charAt(j-1) == s3.charAt(k));
                    dp[j] |= dp[j-1] && s2.charAt(j-1) == s3.charAt(k);
                }
            }
        }
        // return dp[x][y];
        return dp[y];
    }
}
// @lc code=end

