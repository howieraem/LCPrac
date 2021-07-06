/*
 * @lc app=leetcode.cn id=1761 lang=java
 *
 * [1761] 一个图中连通三元组的最小度数
 */


// @lc code=start
class Solution {
    private boolean[][] connected;

    public int minTrioDegree(int n, int[][] edges) {
        // make the capacity just above the maximum n
        connected = new boolean[n + 1][n + 1];
        int[] deg = new int[n + 1];

        for (int i = 0; i < edges.length; ++i) {
            int from = edges[i][0], to = edges[i][1];
            connected[from][to] = connected[to][from] = true;
            ++deg[from];
            ++deg[to]; 
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= n - 2; ++i) {
            for (int j = i + 1; j <= n - 1; ++j) {
                for (int k = j + 1; k <= n; ++k) {
                    if (isConnected(i, j, k)) {
                        // deg of trio(i, j, k) = 
                        // (deg[i] - 2) + (deg[j] - 2) + (deg[k] - 2)
                        int degs = deg[i] + deg[j] + deg[k] - 6;
                        ans = Math.min(ans, degs);
                    }
                }
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private boolean isConnected(int i, int j, int k) {
        return connected[i][j] && connected[i][k]
                && connected[j][i] && connected[j][k]
                && connected[k][i] && connected[k][j];
    }
}
// @lc code=end

