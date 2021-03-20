/*
 * @lc app=leetcode.cn id=474 lang=java
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        // 有'0'和'1'两种背包，最大最小类问题
        int[][] dp = new int[m + 1][n + 1];
        for (String s : strs) {
            int[] cnt = countDigits(s);
            for (int i = m; i >= cnt[0]; --i) {
                for (int j = n; j >= cnt[1]; --j) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - cnt[0]][j - cnt[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }

    private int[] countDigits(String s) {
        int[] cnt = new int[2];
        for (char c : s.toCharArray()) ++cnt[c - '0'];
        return cnt;
    }
}
// @lc code=end

