/*
 * @lc app=leetcode.cn id=87 lang=java
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
    public boolean isScramble(String s1, String s2) {
        // dp[i][j][len] means whether s1[i:i+len] is scramble of s2[j:j+len]
        int n = s1.length();
        if (n != s2.length())  return false;
        char[] chs1 = s1.toCharArray(), chs2 = s2.toCharArray();
        boolean[][][] dp = new boolean[n][n][n+1];

        // single character (len = 1) cases
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (chs1[i] == chs2[j]);
            }
        }

        // len from 2 to n
        for (int len = 2; len <= n; ++len) {
            // enumerate cases of s1
            for (int i = 0; i <= n - len; ++i) {
                // enumerate cases of s2
                for (int j = 0; j <= n - len; ++j) {
                    // split cases
                    for (int k = 1; k <= len - 1; ++k) {
                        if (
                            (dp[i][j][k] && dp[i+k][j+k][len-k]) ||     // substrings not swapped
                            (dp[i][j+len-k][k] && dp[i+k][j][len-k])    // substrings swapped
                        ) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
}
// @lc code=end

