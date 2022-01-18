/*
 * @lc app=leetcode.cn id=363 lang=java
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */
import java.util.TreeSet;


// @lc code=start
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int[][] preSum = new int[m + 1][n + 1];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] + matrix[i][j] - preSum[i][j];
            }
        }

        // Iterate cols in outter loops because m (no. of rows) can be much greater than n (no. of cols)
        int ans = Integer.MIN_VALUE;
        for (int y1 = 0; y1 < n; ++y1) {
            for (int y2 = y1 + 1; y2 <= n; ++y2) {
                TreeSet<Integer> s = new TreeSet<>();
                s.add(0);

                for (int x = 1; x <= m; ++x) {
                    int sum = sumRegion(preSum, 0, y1, x, y2);

                    // TreeSet.ceiling(x) returns the least element >= x.
                    // Since TreeSet is ordered, this method takes O(logN).
                    // Idea explaned in 1D:
                    //  1. sum[i, j] = sum[0, j] - sum[0, i - 1]，是否存在 i 和 j ，使 sum[i, j] <= k 同时最接近 k
                    //  2. 求 sum[0, j] - sum[0, i - 1] <= k 同时保持最大，把这个式子变换一下就会是 sum[0, j] - k <= sum[0, i - 1]
                    //  3. i < j, sum[0, i - 1] 比 sum[0, j] 先得出并添加到 TreeSet 中，因此找是否存在符合条件的最小的 sum[0, i - 1] 
                    //  4. 若存在符合条件的最小的 sum[0, i - 1]，更新 ans = sum[0, j] - sum[0, i - 1]
                    Integer lower = s.ceiling(sum - k);
                    if (lower != null) {
                        ans = Math.max(ans, sum - lower);
                    }
                    if (ans == k)  return k;
                    s.add(sum);
                }
            }
        }
        return ans;
    }

    private int sumRegion(int[][] preSum, int x1, int y1, int x2, int y2) {
        // Same as Q304
        return preSum[x2][y2] - preSum[x1][y2] - preSum[x2][y1] + preSum[x1][y1];
    }
}
// @lc code=end

