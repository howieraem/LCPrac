/*
 * @lc app=leetcode id=240 lang=java
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
    // Two pointers
    // T: O(m + n)
    // S: O(1)
    public boolean searchMatrix(int[][] matrix, int target) {
        final int m = matrix.length;
        if (m == 0) {
            return false;
        }
        final int n = matrix[0].length;
        
        // Equivalent to traversing an implicit binary search tree with the starting point as the root node
        int r = 0;
        int c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                --c;
            } else {   // matrix[r][c] < target
                ++r;
            }
        }
        return false;

        // It is also okay to start searching from the bottom left corner
        // r = m - 1, c = 0;
        // while (r >= 0 && c < n) {...}
    }
}
// @lc code=end

