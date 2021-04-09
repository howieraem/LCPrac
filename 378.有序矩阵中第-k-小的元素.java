/*
 * @lc app=leetcode.cn id=378 lang=java
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
    private int m, n;

    public int kthSmallest(int[][] matrix, int k) {
        m = matrix.length; 
        n = matrix[0].length;
        int l = matrix[0][0], r = matrix[m - 1][n - 1];
        // l is the smallest and r is the greatest in matrix
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (countSmallerInMat(matrix, mid) < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private int countSmallerInMat(int[][] matrix, int mid) {
        int cnt = 0, row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] <= mid) {
                cnt += col + 1;
                ++row;
            } else {
                --col;
            }
        }
        return cnt;
    }
}
// @lc code=end

