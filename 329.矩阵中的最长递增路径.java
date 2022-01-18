/*
 * @lc app=leetcode.cn id=329 lang=java
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
    private static final int[][] DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    private int rows, cols;

    public int longestIncreasingPath(int[][] matrix) {
        int ans = 0;
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)  return ans;
        rows = matrix.length;
        cols = matrix[0].length;
        // memo will store the length of longest increasing path starting from every cell
        int[][] memo = new int[rows][cols];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = Math.max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    private int dfs(int[][] matrix, int row, int col, int[][] memo) {
        if (memo[row][col] != 0)  return memo[row][col];    // memorized search 
        ++memo[row][col];
        for (int[] dir : DIRS) {
            int newRow = row + dir[0], newCol = col + dir[1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[row][col]) {
                memo[row][col] = Math.max(memo[row][col], dfs(matrix, newRow, newCol, memo) + 1);
            }
        }
        return memo[row][col];
    }
}
// @lc code=end

