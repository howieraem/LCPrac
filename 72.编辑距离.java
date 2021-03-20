/*
 * @lc app=leetcode.cn id=72 lang=java
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] dp = new int[m + 1][n + 1];

        // base cases: edit distance from empty string to target string s[:i] or s[:j]
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // skip the current identical characters for both words
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j] + 1,       // delete one character from word1
                        dp[i][j - 1] + 1,       // add one character to word2
                        dp[i - 1][j - 1] + 1    // replace one character
                    );
                }
            }
        }
        return dp[m][n];
    }

    private int min(int opA, int opB, int opC) {
        return Math.min(opA, Math.min(opB, opC));
    }
}
// @lc code=end

