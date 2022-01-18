/*
 * @lc app=leetcode.cn id=1312 lang=java
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
class Solution {
    /*
    public int minInsertions(String s) {
        int n = s.length();

        // dp[i][j] means the minimum number of insertions s[i:j+1] needs. 
        // Base case: 
        // when i == j, dp[i][j] = 0, 
        // meaning that a single character is 
        // already a palindrome. Base cases are
        // already initialized with the array.
        int[][] dp = new int[n][n];
        
        // Note the order of iterations. To get dp[i][j] from
        // dp[i+1][j-1], dp[i][j-1] and dp[i+1][j], iterate
        // x reversely and then y.
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    // Make either s[i+1:j+1] or s[i:j] a palindrome first.
                    dp[i][j] = Math.min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[0][n-1];
    }
    */

    public int minInsertions(String s) {
        int n = s.length();
        int[] dp = new int[n];
        
        for (int i = n - 2; i >= 0; --i) {
            int pre = 0;
            for (int j = i + 1; j < n; ++j) {
                int tmp = dp[j];
                if (s.charAt(i) == s.charAt(j)) {
                    dp[j] = pre;
                } else {
                    dp[j] = Math.min(dp[j], dp[j-1]) + 1;
                }
                pre = tmp;
            }
        }
        return dp[n-1];
    }
}
// @lc code=end

