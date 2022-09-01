import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=664 lang=java
 *
 * [664] 奇怪的打印机
 */

// @lc code=start
class Solution {
    public int strangePrinter(String s) {
        final int n = s.length();
        if (n < 2)  return n;

        // dp[i][j] stands for the minimum steps to print s[i:j+1]
        int[][] dp = new int[n + 1][n + 1];

        // 枚举长度 -> 枚举左端点 -> 枚举分割点
        for (int len = 1; len <= n; ++len) {
            for (int l = 0; l < n - len + 1; ++l) {
                int r = l + len - 1;
                dp[l][r] = dp[l + 1][r] + 1;    // 只打印 l 这个位置
                for (int k = l + 1; k <= r; ++k) {
                    if (s.charAt(l) == s.charAt(k)) {
                        // 不只打印 l 这个位置，而是从 l 打印到 k
                        dp[l][r] = Math.min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
}
// @lc code=end

