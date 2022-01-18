import java.util.*;
/*
 * @lc app=leetcode.cn id=675 lang=java
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
    private static final int[] D = {-1, 0, 1, 0, -1};
    private List<List<Integer>> forest;
    private int m, n;

    public int cutOffTree(List<List<Integer>> forest) {
        List<int[]> trees = new ArrayList<>();
        m = forest.size(); 
        n = forest.get(0).size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int h = forest.get(i).get(j);
                if (h > 1)  trees.add(new int[]{h, i, j});
            }
        }
        if (trees.size() == 0)  return 0;
        if (forest.get(0).get(0) == 0)  return -1;
        this.forest = forest;
        Collections.sort(trees, (t1, t2) -> t1[0] - t2[0]);

        int ans = 0, sx = 0, sy = 0;
        for (int[] tree : trees) {
            // Accumulate the distance between each pair of cur-next trees.
            int d = bfs(sx, sy, tree[1], tree[2]);
            if (d < 0)  return -1;
            ans += d;
            sx = tree[1];
            sy = tree[2];
        }
        return ans;
    }

    private int bfs(int sx, int sy, int tx, int ty) {
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] seen = new boolean[m][n];   // Since multiple BFS is required, do not modify the original forest
        q.offer(new int[]{sx, sy, 0});  // x, y, path_dist
        while (!q.isEmpty()) {
            int[] p = q.poll();
            if (p[0] == tx && p[1] == ty)  return p[2];
            for (int i = 0; i < 4; ++i) {
                int x = p[0] + D[i], y = p[1] + D[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !seen[x][y] && forest.get(x).get(y) > 0) {
                    seen[x][y] = true;
                    q.add(new int[]{x, y, p[2] + 1});
                }
            }
        }
        return -1;  // no valid path from (sx, sy) to (tx, ty)
    }
}
// @lc code=end

