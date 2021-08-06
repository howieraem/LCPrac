import java.util.*;
/*
 * @lc app=leetcode.cn id=542 lang=java
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
    private static final int[] D = {-1, 0, 1, 0, -1};

    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        Queue<int[]> q = new ArrayDeque<>();
        boolean hasOne = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.offer(new int[]{i, j});
                } else {
                    hasOne = true;
                    /* 
                    Mark original 1 as -1 instead to avoid
                    confusion while calculating steps later.
                    In this way, no need to create a new
                    ans matrix to loop over.
                    */
                    mat[i][j] = -1;
                }
            }
        }
        // if (!hasOne)  return mat;
        if (!hasOne)  return new int[m][n];

        // int[][] ans = new int[m][n];
        while (!q.isEmpty()) {
            int nq = q.size();
            for (int i = 0; i < nq; ++i) {
                int[] p = q.poll();
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + D[j], y = p[1] + D[j + 1];
                    // if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] != 1)
                    if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] != -1)
                        continue;

                    q.offer(new int[]{x, y});
                    mat[x][y] = mat[p[0]][p[1]] + 1;
                    // mat[x][y] = 2;
                    // ans[x][y] = ans[p[0]][p[1]] + 1;
                }
            }
        }
        // return ans;
        return mat;
    }
}
// @lc code=end

