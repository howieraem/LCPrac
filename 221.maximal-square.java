import java.util.Arrays;

/*
 * @lc app=leetcode id=221 lang=java
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
    /* // Original DP
    public int maximalSquare(char[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;
        int[][] dp = new int[m][n];
        int len = 0;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == '1') { 
                dp[i][0] = 1;
                len = 1;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == '1') { 
                dp[0][j] = 1;
                len = 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    len = Math.max(len, dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1);
                }
            }
        }
        return len * len;
    }
    */

    /*
    // DP with optimized space v1
    public int maximalSquare(char[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;
        int[] cur = new int[n], pre = new int[n];
        int len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = Math.min(pre[j - 1], Math.min(pre[j], cur[j - 1])) + 1;
                }
                len = Math.max(len, cur[j]);
            }
            System.arraycopy(cur, 0, pre, 0, n);
            Arrays.fill(cur, 0);
        }
        return len * len;
    }
    */

    // DP with optimized space v2
    public int maximalSquare(char[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;
        int[] cur = new int[n];
        int len = 0, pre = Integer.MAX_VALUE, tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp = cur[j];
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    cur[j] = matrix[i][j] - '0';
                } else {
                    cur[j] = Math.min(pre, Math.min(cur[j], cur[j - 1])) + 1;
                }
                len = Math.max(len, cur[j]);
                pre = tmp;
            }
        }
        return len * len;
    }
}
// @lc code=end

