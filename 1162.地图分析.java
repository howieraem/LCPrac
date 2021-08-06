import java.util.*;
/*
 * @lc app=leetcode.cn id=1162 lang=java
 *
 * [1162] 地图分析
 */

// @lc code=start
class Pair {
    int x, y;

    public Pair(int _x, int _y) {
        x = _x;
        y = _y;
    }

    // @Override
    // public boolean equals(Object other) {
    //     if (!(other instanceof Pair))  return false;
    //     Pair o = (Pair) other;
    //     return o.x == x && o.y == y;
    // }

    // @Override
    // public int hashCode() {
    //     return Objects.hash(x, y);
    // }
}

class Solution {
    private static final int[] D = {-1, 0, 1, 0, -1};

    public int maxDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean hasLand = false;
        // Multi-source BFS: multiple starting points
        Queue<Pair> q = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    hasLand = true;
                    q.offer(new Pair(i, j));
                }
            }
        }
        // No land or no ocean
        if (!hasLand || q.size() == m * n)   return -1;

        int ans = -1;
        // Set<Pair> seen = new HashSet<>();
        // Note: If not allowed to modify grid and a set is needed,
        // use x * n + y as key, which is unique and more efficient 
        // than Objects.hash(x, y). 
        while (!q.isEmpty()) {
            int nq = q.size();
            for (int i = 0; i < nq ; ++i) {
                Pair p = q.poll();
                for (int j = 0; j < 4; ++j) {
                    int x = p.x + D[j], y = p.y + D[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                        Pair next = new Pair(x, y);
                        // if (!seen.contains(next)) {
                        //     seen.add(next);
                        //     q.offer(next);
                        // }
                        q.offer(next);
                        grid[x][y] = 2;     // mark seen
                    }
                }
            }
            ++ans;
        }
        return ans;
    }
}
// @lc code=end

