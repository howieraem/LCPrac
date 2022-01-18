import java.util.*;
/*
 * @lc app=leetcode.cn id=120 lang=java
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        final int n = triangle.size();

        /* From top to bottom */
        // // dp[i][j]: sum of path ending at ith row and jth col
        // int[][] dp = new int[n][n];
        // dp[0][0] = triangle.get(0).get(0);

        // for (int i = 1; i < n; ++i) {
        //     dp[i][0] = dp[i - 1][0] + triangle.get(i).get(0);   // left edge

        //     // everything in the middle
        //     for (int j = 1; j < i; ++j) {
        //         dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle.get(i).get(j);
        //     }
        //     dp[i][i] = dp[i - 1][i - 1] + triangle.get(i).get(i);   // right edge
        // }
        // return Arrays.stream(dp[n - 1]).min().getAsInt();

        /* From bottom to top, equivalent path but simpler code */
        // // dp[i][j]: sum of path ending at ith row and jth col.
        // int[][] dp = new int[n][n];
        // dp[n - 1] = triangle.get(n - 1).stream().mapToInt(i -> i).toArray();

        // for (int i = n - 2; i >= 0; --i) {
        //     for (int j = 0; j <= i; ++j) {
        //         dp[i][j] = Math.min(dp[i + 1][j + 1], dp[i + 1][j]) + triangle.get(i).get(j);
        //     }
        // }
        // return dp[0][0];

        /* From bottom to top, optimized space */
        // Add 1 to size to avoid initializing the last row with the last row of triangle
        // (this base case can be moved to state transitions)
        int[] dp = new int[n + 1];

        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
}
// @lc code=end

