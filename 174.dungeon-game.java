import java.util.*;
/*
 * @lc app=leetcode id=174 lang=java
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        final int m = dungeon.length, n = dungeon[0].length;

        // dp[i][j]: min. HP required to reach the cell at ith row and jth column
        int[][] dp = new int[m + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Explanation: an extra row and an extra column are padded to the dp.
        // Given the knight can only travel to the right or the bottom with
        // HP >= 1, we can assume that the knight's HP at the princess cell 
        // is the minimum possible value 1. Thus, dp array is filled from
        // bottom right to top left. The base cases are that dp cells next to
        // the princess cell are 1 (indicating the HP after arriving at the 
        // princess cell, the padded cells do not affect final HP). The padding
        // would avoid coding if...else... boundary cases in loop.
        dp[m][n - 1] = dp[m - 1][n] = 1; 
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = Math.max(1, Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
}
// @lc code=end

