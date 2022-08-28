/*
 * @lc app=leetcode id=562 lang=java
 *
 * [562] Longest Line of Consecutive One in Matrix
 */

// @lc code=start
class Solution {
    private static final int[][] D = {{-1, 0}, {0, -1}, {-1, -1}, {-1, 1}};

    // T: O(m * n)
    // S: O(m * n), can be optimized to O(m) or O
    public int longestLine(int[][] mat) {
        final int m = mat.length, n = mat[0].length;

        // 4 directions: horizontal, vertical, diagonal and antidiagonal
        int[][][] dp = new int[m][n][4];

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    for (int d = 0; d < 4; ++d) {
                        dp[i][j][d] = 1;
        
                        // DP is bottom-up, so need to check the previous states 
                        // rather than next states in BFS/DFS
                        int pre_i = i + D[d][0], pre_j = j + D[d][1];
                        if (0 <= pre_i && pre_i < m && 0 <= pre_j && pre_j < n) {
                            dp[i][j][d] += dp[pre_i][pre_j][d];
                        }
                        ans = Math.max(ans, dp[i][j][d]);
                    }
                }
            }
        }
        return ans;
    }
}
// @lc code=end

