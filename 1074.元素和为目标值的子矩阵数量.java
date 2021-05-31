import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=1074 lang=java
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int[][] sum = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int ans = 0;

        // Below is O(m^2 * n^2)
        // for (int i = 1; i <= m; ++i) {
        //     for (int j = 1; j <= n; ++j) {
        //         for (int p = 1; p <= i; ++p) {
        //             for (int q = 1; q <= j; ++q) {
        //                 if (sum[i][j] - sum[p - 1][j] - sum[i][q - 1] + sum[p - 1][q - 1] == target) {
        //                     ++ans;
        //                 }
        //             }
        //         }
        //     }
        // }

        // Optimized: if three sides of a rectangle are known, then the 4th side can be determined directly.
        // The "side" here means a sub-matrix's boundary. Time complexity O(m^2 * n).
        for (int top = 1; top <= m; ++top) {
            for (int bottom = top; bottom <= m; ++bottom) {
                int cur = 0;
                Map<Integer, Integer> map = new HashMap<>();
                for (int row = 1; row <= n; ++row) {
                    cur = sum[bottom][row] - sum[top - 1][row];
                    if (cur == target) { 
                        ++ans; 
                    }
                    if (map.containsKey(cur - target)) {
                        ans += map.get(cur - target);
                    }
                    map.put(cur, map.getOrDefault(cur, 0) + 1);
                }
            }
        }

        return ans;
    }
}
// @lc code=end

