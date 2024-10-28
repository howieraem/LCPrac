import java.util.*;
/*
 * @lc app=leetcode id=120 lang=java
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
    // 2D DP
    // T: O(n ^ 2)
    // S: O(n) after state compression
    public int minimumTotal(List<List<Integer>> triangle) {
        final int n = triangle.size();
        
        // dp[i][j] means the minimum cost of path
        // ending at ith row and jth column.
        //
        // Traversing from bottom to top is equivalent to
        // traversing from top to bottom. The former
        // will have less code.
        //
        // Add 1 to avoid initializing the base case
        // which is the last row of triangle.
        // int[][] dp = new int[n + 1][n + 1];
        int[] dp = new int[n + 1];

        // Compress states since dp[i][j] depends on dp[i+1][j] and dp[i+1][j+1] only
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);
                dp[j] = Math.min(dp[j], dp[j + 1]) + triangle.get(i).get(j);
            }
        }
        // return dp[0][0];
        return dp[0];
    }
}
// @lc code=end

