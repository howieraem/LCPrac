import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=516 lang=java
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        /* dp[i][j] means the longest palindrome subseq in s[i:j+1] */
        // int[][] dp = new int[n][n];
        int[] dp = new int[n];

        /* base cases: each character itself is a palindrome */
        // for (int i = 0; i < n; ++i) {
        //     dp[i][i] = 1;
        // }
        Arrays.fill(dp, 1);
        
        for (int i = n - 2; i >= 0; --i) {
            int pre = 0;
            for (int j = i + 1; j < n; ++j) {
                int tmp = dp[j];    // stores dp[i + 1][j - 1]

                if (s.charAt(i) == s.charAt(j)) {
                    /* add 2 for both s[i] and s[j] */
                    // dp[i][j] = dp[i + 1][j - 1] + 2;
                    dp[j] = pre + 2;
                } else {
                    /* choose the character such that subseq is longer */
                    // dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }
                pre = tmp;
            }
        }
        // return dp[0][n - 1];
        return dp[n - 1];
    }
}
// @lc code=end

