import java.util.*;
/*
 * @lc app=leetcode.cn id=1466 lang=java
 *
 * [1466] 重新规划路线
 */

// @lc code=start
class Solution {
    @SuppressWarnings("unchecked")
    public int minReorder(int n, int[][] connections) {
        // Build the graph adjacency matrix and store the edge direction.
        // Edge direction 0 means from conn[0] to conn[1], and vice versa.
        List<int[]>[] A = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            A[i] = new ArrayList<>();
        }
        for (int[] conn : connections) {
            A[conn[0]].add(new int[]{conn[1], 1});
            A[conn[1]].add(new int[]{conn[0], 0});
        }

        // Do DFS/BFS and count the number of edges with reversed direction 
        // (edge direction marked as 1)
        int ans = 0;
        boolean[] seen = new boolean[n];
        seen[0] = true;
        // Stack<Integer> s = new Stack<>();
        Queue<Integer> q = new ArrayDeque<>();
        // s.push(0);
        q.offer(0);
        // while (!s.empty()) {
        while (!q.isEmpty()) {
            // int sz = s.size();
            int sz = q.size();
            while (sz-- > 0) {
                // int src = s.pop();
                int src = q.poll();
                for (int[] e : A[src]) {
                    int dst = e[0], dir = e[1];
                    if (!seen[dst]) {
                        // s.push(dst);
                        q.offer(dst);
                        seen[dst] = true;
                        if (dir == 1)  ++ans;
                    }
                }
            }
        }
        return ans;
    }
}
// @lc code=end

 