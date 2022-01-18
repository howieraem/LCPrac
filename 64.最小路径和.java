/*
 * @lc app=leetcode.cn id=64 lang=java
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
    public int minPathSum(int[][] grid) {
        final int m = grid.length, n = grid[0].length;
        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         if (i > 0 || j > 0) {
        //             if (i == 0)  grid[i][j] += grid[i][j - 1];  // top edge
        //             else if (j == 0)  grid[i][j] += grid[i - 1][j];     // left edge
        //             else  grid[i][j] += Math.min(grid[i][j - 1], grid[i - 1][j]);   // other locations
        //         }
        //     }
        // }

        // Base cases: top and left edges
        for (int i = 1; i < m; ++i)  grid[i][0] += grid[i - 1][0];
        for (int j = 1; j < n; ++j)  grid[0][j] += grid[0][j - 1];

        // Other locations
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] += Math.min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[m - 1][n - 1];
    }
}
// @lc code=end

