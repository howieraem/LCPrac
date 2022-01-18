/*
 * @lc app=leetcode.cn id=1091 lang=java
 *
 * [1091] 二进制矩阵中的最短路径
 */
import java.util.Queue;
import java.util.ArrayDeque;
// import java.util.Set;
// import java.util.HashSet;
// import java.util.Objects;

// @lc code=start
class Pair {
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // @Override
    // public boolean equals(Object other) {
    //     if (!(other instanceof Pair))  return false;
    //     Pair o = (Pair) other;
    //     return x == o.x && y == o.y;
    // }

    // @Override
    // public int hashCode() {
    //     return Objects.hash(x, y);
    // }
}

class Solution {
    private static final int[][] D = new int[][]{
        {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
    };

    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1)  return -1;
        int n = grid.length, last = n - 1;
        Queue<Pair> q = new ArrayDeque<>();
        q.offer(new Pair(0, 0));
        // Set<Pair> visited = new HashSet<>();
        int ans = 0;

        while (!q.isEmpty()) {
            int nq = q.size();
            for (int i = 0; i < nq; ++i) {
                Pair p = q.poll();
                // if (visited.contains(p))  continue;
                if (grid[p.x][p.y] == 1)  continue;
                if (p.x == last && p.y == last) {
                    return ans + 1;
                }
                for (int d = 0; d < 8; ++d) {
                    int nx = p.x + D[d][0], ny = p.y + D[d][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 1) {
                        q.offer(new Pair(nx, ny));
                    }
                }
                // visited.add(p);
                grid[p.x][p.y] = 1;
            }
            ++ans;
        }
        return -1;
    }
}
// @lc code=end

