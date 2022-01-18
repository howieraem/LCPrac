/*
 * @lc app=leetcode.cn id=1473 lang=java
 *
 * [1473] 粉刷房子 III
 */

// @lc code=start
class Solution {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int maxCost = 1;
        for (int[] c : cost) {
            maxCost += Math.max(c[0], c[1]);
        }
        // maxCost is just above the upper bound of ans

        // 定义 dp[i][j][k] 为考虑前 i 间房子，且第 i 间房子的颜色编号为 j，
        // 前 i 间房子形成的分区数量为 k 的所有方案中的「最小上色成本」
        int[][][] dp = new int[m + 1][n + 1][target + 1];

        // target = 0 is meaningless
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                dp[i][j][0] = maxCost;
            }
        }

        for (int i = 1; i <= m; ++i) {
            int color = houses[i - 1];
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= target; ++k) {
                    if (k > i) {
                        // blocks more than houses is impossible
                        dp[i][j][k] = maxCost;
                        continue;
                    }

                    if (color != 0) {
                        // case: already colored
                        if (j == color) {
                            int tmp = maxCost;
                            for (int p = 1; p <= n; ++p) {
                                if (p != j) {
                                    tmp = Math.min(tmp, dp[i - 1][p][k - 1]);
                                }
                            }
                            dp[i][j][k] = Math.min(dp[i - 1][j][k], tmp);
                        } else {
                            // prevent state transition if color doesn't match case j
                            dp[i][j][k] = maxCost;
                        }
                    } else {
                        // case: not colored
                        int c = cost[i - 1][j - 1], tmp = maxCost;
                        for (int p = 1; p <= n; ++p) {
                            if (p != j) {
                                tmp = Math.min(tmp, dp[i - 1][p][k - 1]);
                            }
                        }
                        dp[i][j][k] = Math.min(dp[i - 1][j][k], tmp) + c;
                    }
                }
            }
        }

        int ans = maxCost;
        for (int i = 1; i <= n; ++i) {
            ans = Math.min(ans, dp[m][i][target]);
        }
        return ans == maxCost ? -1 : ans;
    }
}
// @lc code=end

