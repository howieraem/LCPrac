/*
 * @lc app=leetcode id=329 lang=java
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
    private static final int[] D = {-1, 0, 1, 0, -1};

    // T: O(m * n)
    // S: O(m * n)
    public int longestIncreasingPath(final int[][] matrix) {
        final int m = matrix.length, n = matrix[0].length;
        int ans = 0;

        // Memoized DFS starting from each cell.
        // DFS is needed because the path can contain all 4 directions.
        int[][] memo = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    private static int dfs(final int[][] mat, int i, int j, int[][] memo) {
        if (memo[i][j] != 0) return memo[i][j];
        int maxLen = 1;
        for (int d = 0; d < 4; ++d) {
            int ni = i + D[d], nj = j + D[d + 1];
            if (0 <= ni && ni < mat.length && 0 <= nj && nj < mat[0].length && 
                mat[ni][nj] > mat[i][j]) {
                maxLen = Math.max(maxLen, dfs(mat, ni, nj, memo) + 1);
            }
        }
        memo[i][j] = maxLen;
        return maxLen;
    }
}
// @lc code=end

