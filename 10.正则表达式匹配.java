/*
 * @lc app=leetcode.cn id=10 lang=java
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
    public boolean isMatch(String s, String p) {
        int m = s.length(), n = p.length();
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p.charAt(j - 1) == '*') {
                    dp[i][j] |= dp[i][j - 2];  // skip the * character for 0 match
                    if (charsMatch(s, i, p, j - 1)) {
                        // match any times of s[i - 1]
                        dp[i][j] |= dp[i - 1][j];
                    }
                } else {
                    if (charsMatch(s, i, p, j)) {
                        // singleton match
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }

    private static boolean charsMatch(String s, int i, String p, int j) {
        return i > 0 && (s.charAt(i - 1) == p.charAt(j - 1) || p.charAt(j - 1) == '.');
    }
}
// @lc code=end

