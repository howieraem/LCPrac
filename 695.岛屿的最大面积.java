import java.util.*;
/*
 * @lc app=leetcode.cn id=695 lang=java
 *
 * [695] 岛屿的最大面积
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
    private static final int[] DIRNS = {-1, 0, 1, 0, -1};

    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;

        Stack<Pair> stack = new Stack<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = 1;
                    grid[i][j] = 0;
                    stack.clear();
                    stack.add(new Pair(i, j));

                    while (!stack.empty()) {
                        Pair p = stack.pop();
                        for (int k = 0; k < 4; ++k) {
                            int x = p.x + DIRNS[k], y = p.y + DIRNS[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                ++area;
                                grid[x][y] = 0;
                                stack.add(new Pair(x, y));
                            }
                        }
                    }
                    ans = Math.max(ans, area);
                }
            }
        }
        return ans;
    }
}
// @lc code=end

