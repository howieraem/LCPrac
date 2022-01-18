/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        if (matrix.length == 0 || matrix[0].length == 0)  return res;
        int rows = matrix.length, cols = matrix[0].length;
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; ++i) {
                res.add(matrix[top][i]);
            }
            for (int j = top + 1; j <= bottom; ++j) {
                res.add(matrix[j][right]);
            }
            if (left < right && top < bottom) {
                for (int i = right - 1; i > left; --i) {
                    res.add(matrix[bottom][i]);
                }
                for (int j = bottom; j > top; --j) {
                    res.add(matrix[j][left]);
                }
            }
            ++left;
            --right;
            ++top;
            --bottom;
        }
        return res;
    }
}
// @lc code=end

