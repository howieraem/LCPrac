/*
 * @lc app=leetcode.cn id=994 lang=java
 *
 * [994] 腐烂的橘子
 */
import java.util.Queue;
import java.util.ArrayDeque;

// @lc code=start
class Solution {
    // Find shortest path with BFS.
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        int good = 0;

        Queue<int[]> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)  q.offer(new int[]{i, j});
                else if (grid[i][j] == 1)  ++good;
            }
        }
        if (good == 0)  return 0;

        while (!q.isEmpty()) {
            int qs = q.size();
            for (int i = 0; i < qs; ++i) {
                int[] coords = q.poll();
                int x = coords[0], y = coords[1];
                if (x > 0 && grid[x - 1][y] == 1) { 
                    q.offer(new int[]{x - 1, y});
                    grid[x - 1][y] = 2;
                }
                if (x < m - 1 && grid[x + 1][y] == 1) { 
                    q.offer(new int[]{x + 1, y});
                    grid[x + 1][y] = 2;
                }
                if (y > 0 && grid[x][y - 1] == 1) { 
                    q.offer(new int[]{x, y - 1});
                    grid[x][y - 1] = 2;
                }
                if (y < n - 1 && grid[x][y + 1] == 1) {
                    q.offer(new int[]{x, y + 1});
                    grid[x][y + 1] = 2;
                }
            }
            ++ans;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        // minus one because the last enqueue will not affect more oranges
        return ans - 1;
    }
}
// @lc code=end

