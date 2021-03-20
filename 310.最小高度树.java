/*
 * @lc app=leetcode.cn id=310 lang=java
 *
 * [310] 最小高度树
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        if (n == 1) {
            res.add(0);
            return res;
        }

        int[] degree = new int[n];
        List<List<Integer>> adjacency = new ArrayList<>();
        for (int i = 0; i < n; ++i)  adjacency.add(new ArrayList<>());
        for (int[] edge : edges) {
            ++degree[edge[0]];
            ++degree[edge[1]];
            adjacency.get(edge[0]).add(edge[1]);
            adjacency.get(edge[1]).add(edge[0]);
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            // visit leaf nodes first (with degree 1)
            if (degree[i] == 1)  q.offer(i);
        }

        int resLength = n;
        while (resLength > 2) {
            // There can only be either one or two roots with minimum height.
            // For example, if there are 3 nodes all with shortest path,
            // there has to be a loop and thus the graph is not a tree.
            // 图论：每棵树的中心由一个点或两个相邻点组成
            int sz = q.size();
            resLength -= sz;
            for (int i = 0; i < sz; ++i) {
                int cur = q.poll();
                for (int neighbor : adjacency.get(cur)) {
                    --degree[neighbor];
                    if (degree[neighbor] == 1)  q.offer(neighbor);
                }
            }
        }

        while (!q.isEmpty())  res.add(q.poll());
        return res;
    }
}
// @lc code=end

