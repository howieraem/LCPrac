/*
 * @lc app=leetcode.cn id=1143 lang=java
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m+1][n+1];     // add 1 for base case empty strings ""
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // originally max([dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]]), but
                    // dp[i - 1][j - 1] is always the smallest and thus can be ignored.
                    // Use dp[i - 1][j] if text1[i] is not in LCS.
                    // Use dp[i][j - 1] if text2[j] is not in LCS.
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}
// @lc code=end

