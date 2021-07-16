/*
 * @lc app=leetcode.cn id=688 lang=java
 *
 * [688] “马”在棋盘上的概率
 */

// @lc code=start
class Solution {
    private static final int[] DX = {-2, -2, -1, -1, 1, 1, 2, 2};
    private static final int[] DY = {-1, 1, -2, 2, -2, 2, -1, 1};
    private double[][][] memo;
    private static final int MAX_N = 25, MAX_K = 100;

    public double knightProbability(int n, int k, int row, int column) {
        memo = new double[MAX_N + 1][MAX_N + 1][MAX_K + 1];
        return dfs(n, k, row, column);
    }

    private double dfs(int n, int k, int r, int c) {
        // Base cases
        if (r < 0 || r >= n || c < 0 || c >= n)  return 0.;
        if (k == 0)  return 1.;

        // Memorized recursion to reduce computation
        if (memo[r][c][k] != 0)  return memo[r][c][k];

        // Search all possibilities from current position
        double ans = 0.;
        for (int i = 0; i < 8; ++i) {
            int nx = r + DX[i], ny = c + DY[i];
            // The probability to take one of the eight possibilities is equal
            ans += dfs(n, k - 1, nx, ny) / 8.;
        }

        memo[r][c][k] = ans;
        return ans;
    }
}
// @lc code=end

