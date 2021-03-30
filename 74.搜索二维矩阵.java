/*
 * @lc app=leetcode.cn id=74 lang=java
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0)  return false;
        int n = matrix[0].length;

        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / n, j = mid % n;

            int midElem = matrix[i][j];
            if (target > midElem)  l = mid + 1;
            else if (target < midElem)  r = mid - 1;
            else  return true;
        }
        return false;
    }
}
// @lc code=end

