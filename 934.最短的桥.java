import java.util.*;
/*
 * @lc app=leetcode.cn id=934 lang=java
 *
 * [934] 最短的桥
 */

// @lc code=start
class Pair {
    int x, y;

    public Pair(int _x, int _y) {
        x = _x;
        y = _y;
    }
}

class Solution {
    private int[][] grid;
    private int m, n;
    private int[] D = new int[]{-1, 0, 1, 0, -1};

    // Multi-start BFS
    // T: O(m * n) as each cell is visited constant times
    // S: O(m * n)
    public int shortestBridge(int[][] grid) {
        this.grid = grid;
        m = grid.length; 
        n = grid[0].length;

        // Do DFS to find one of the islands
        Queue<Pair> q = new ArrayDeque<>();
        boolean notFound = true;
        for (int i = 0; i < m && notFound; ++i) {
            for (int j = 0; j < n && notFound; ++j) {
                if (grid[i][j] == 1) {
                    dfs(q, i, j);
                    notFound = false;   // do NOT process the other island
                }
            }
        }

        // Do BFS to find the shortest path to another island
        int ans = -1;
        while (!q.isEmpty()) {
            int nq = q.size();
            while (nq-- != 0) {
                Pair p = q.poll();
                for (int d = 0; d < 4; ++d) {
                    int x = p.x + D[d], y = p.y + D[d + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2)  continue;
                    if (grid[x][y] == 1)  return ans + 1;
                    grid[x][y] = 2;
                    q.offer(new Pair(x, y));
                }
            }
            ++ans;
        }
        return ans;
    }

    private void dfs(Queue<Pair> q, int i, int j) {
        grid[i][j] = 2;  // mark one of the islands visited
        q.offer(new Pair(i, j));    // each part of this island is a src of BFS
        for (int k = 0; k < 4; ++k) {
            int x = i + D[k], y = j + D[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                dfs(q, x, y);
            }
        }
    }
}
// @lc code=end

