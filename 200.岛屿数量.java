/*
 * @lc app=leetcode.cn id=200 lang=java
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    private int h, w;

    public int numIslands(char[][] grid) {
        h = grid.length;
        if (h == 0)  return 0;
        w = grid[0].length;
        // if (w == 0)  return 0;
        int res = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    private void dfs(char[][] grid, int i, int j) {
        grid[i][j] = '0';   // visited
        if (i - 1 >= 0 && grid[i-1][j] == '1') dfs(grid, i - 1, j);
        if (i + 1 < h && grid[i+1][j] == '1') dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j-1] == '1') dfs(grid, i, j - 1);
        if (j + 1 < w && grid[i][j+1] == '1') dfs(grid, i, j + 1);
    }
}
// @lc code=end

