import java.util.Arrays;

/*
 * @lc app=leetcode id=221 lang=java
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
    /* 
    // Original 2D DP
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
                    // side len with (i, j) as the bottom right corner
                    dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    len = Math.max(len, dp[i][j]);
                }
            }
        }
        return len * len;
    }
    */

    /*
    // 2D DP with optimized space v1
    public int maximalSquare(char[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;
        int[] dp_cur = new int[n], dp_pre = new int[n];
        int len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp_cur[j] = matrix[i][j] - '0';
                } else {
                    dp_cur[j] = Math.min(dp_pre[j - 1], Math.min(dp_pre[j], dp_cur[j - 1])) + 1;
                }
                len = Math.max(len, dp_cur[j]);
            }

            // copy dp_cur to dp_pre, and zero dp_cur
            System.arraycopy(dp_cur, 0, dp_pre, 0, n);
            Arrays.fill(dp_cur, 0);
        }
        return len * len;
    }
    */

    // 2D DP with optimized space v2
    // T: O(m * n)
    // S: O(n) state compression
    public int maximalSquare(char[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;
        int[] dp = new int[n];
        int len = 0; 
        int pre = Integer.MAX_VALUE;  // dp[i - 1][j - 1]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = dp[j];
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    // Cases:
                    // 1. left or top edge
                    // 2. non-one cells
                    dp[j] = matrix[i][j] - '0';
                } else {
                    dp[j] = Math.min(pre, Math.min(dp[j], dp[j - 1])) + 1;
                }
                len = Math.max(len, dp[j]);
                pre = tmp;
            }
        }
        return len * len;
    }
}
// @lc code=end

