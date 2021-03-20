/*
 * @lc app=leetcode.cn id=59 lang=java
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    public int[][] generateMatrix(int n) {
        int num = 1;
        int[][] mat = new int[n][n];
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                mat[top][i] = num;
                ++num;
            }
            for (int j = top + 1; j <= bottom; ++j) {
                mat[j][right] = num;
                ++num;
            }
            if (left < right && top < bottom) {
                for (int i = right - 1; i > left; --i) {
                    mat[bottom][i] = num;
                    ++num;
                }
                for (int j = bottom; j > top; --j) {
                    mat[j][left] = num;
                    ++num;
                }
            }
            ++left; --right; ++top; --bottom;
        }
        return mat;
    }
}
// @lc code=end

