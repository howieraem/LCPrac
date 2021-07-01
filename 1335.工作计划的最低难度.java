/*
 * @lc app=leetcode.cn id=1335 lang=java
 *
 * [1335] 工作计划的最低难度
 */

// @lc code=start
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;
        if (n < d)  return -1;
        
        int[][] dp = new int[n][d];
        // Base case: d = 1
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = Math.max(dp[i - 1][0], jobDifficulty[i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < d; ++j) {
                // Default dp[i][j] is set to (just above) the max possible sum of difficulties 10 * 1000.
                // Don't use Integer.MAX_VALUE here to avoid possible overflow later.
                dp[i][j] = 10001;

                int max = -1;
                for (int k = i; k > 0; --k) {
                    // Find the max difficulty for jobs before the i-th job
                    max = Math.max(max, jobDifficulty[k]);

                    // Include the k-th job in the current day or a new day,
                    // to minimize the sum of difficulties
                    dp[i][j] = Math.min(dp[i][j], dp[k - 1][j - 1] + max);
                }
            }
        }
        return dp[n - 1][d - 1];
     }
}
// @lc code=end

