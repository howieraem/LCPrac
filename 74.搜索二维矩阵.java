/*
 * @lc app=leetcode.cn id=74 lang=java
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // Flatten the matrix indices and use division/mod to recover 2D coordinates
        int n = matrix[0].length;
        int l = 0, r = matrix.length * n - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            int i = m / n, j = m % n;
            if (target == matrix[i][j])  return true;
            if (target > matrix[i][j])  l = m + 1;
            else  r = m - 1;
        }
        return false;
    }
}
// @lc code=end
