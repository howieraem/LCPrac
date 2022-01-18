import java.util.*;
/*
 * @lc app=leetcode.cn id=733 lang=java
 *
 * [733] 图像渲染
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

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int m = image.length, n = image[0].length;
        int oldColor = image[sr][sc];
        if (oldColor == newColor)  return image;
        Stack<Pair> stack = new Stack<>();
        stack.push(new Pair(sr, sc));
        while (!stack.empty()) {
            Pair p = stack.pop();
            image[p.x][p.y] = newColor;

            for (int i = 0; i < 4; ++i) {
                int x = p.x + DIRNS[i], y = p.y + DIRNS[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == oldColor) {
                    stack.push(new Pair(x, y));
                }
            }
        }
        return image;
    }
}
// @lc code=end

