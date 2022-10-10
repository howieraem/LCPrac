/*
 * @lc app=leetcode id=778 lang=java
 *
 * [778] Swim in Rising Water
 */
import java.util.PriorityQueue;

// @lc code=start
class Solution {
    private static final int[] D = {1, 0, -1, 0, 1};

    // Simplified Dijkstra's algorithm
    // T: O(m * n * log(m * n))
    // S: O(m * n)
    // (this is more generalized than the cpp version)
    public int swimInWater(int[][] grid) {
        final int m = grid.length, n = grid[0].length;

        // With custom comparator, it's slightly more memory-efficient than storing tuples (grid[r][c], r, c)
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((p1, p2) -> Integer.compare(grid[p1[0]][p1[1]], grid[p2[0]][p2[1]]));
        boolean[][] vis = new boolean[m][n];
        
        minHeap.offer(new int[] {0, 0});
        vis[0][0] = true;

        int ans = 0;
        while (!minHeap.isEmpty()) {
            var cur = minHeap.poll();
            ans = Math.max(ans, grid[cur[0]][cur[1]]);
            if (cur[0] == m - 1 && cur[1] == n - 1) break;

            for (int d = 0; d < 4; ++d) {
                int r = cur[0] + D[d], c = cur[1] + D[d + 1];
                if (0 <= r && r < m && 0 <= c && c < n && !vis[r][c]) {
                    minHeap.offer(new int[] {r, c});
                    vis[r][c] = true;
                }
            }
        }

        return ans;
    }
}
// @lc code=end

