import java.util.*;
/*
 * @lc app=leetcode.cn id=802 lang=java
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
    /*
    // BFS-based topological sort
    // T: O(V + E)
    // S: O(V + E)
    public List<Integer> eventualSafeNodes(int[][] graph) {
        // A node is safe if either its out degree is 0, or nodes it points to are safe.
        // Reverse all edge directions (out degree becomes in degree) and do topological sort.
        int n = graph.length;
        int[] inDeg = new int[n];
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                // reverse edge direction, j -> i
                adj.get(j).add(i);
            }
            inDeg[i] += graph[i].length;
        }

        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.add(i);
            }  
        }

        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.get(u)) {
                if (--inDeg[v] == 0) {
                    q.add(v);
                }
            }
        }

        // At this point, nodes with inDeg > 0 are not safe
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0)  res.add(i);
        }
        return res;
    }
    */
    
    // DFS-based topological sort (3 states)
    private static enum State {
        UNVISITED,
        VISITING,
        SAFE,
    }

    private int[][] graph;
    private State[] nodeStates;

    public List<Integer> eventualSafeNodes(int[][] graph) {
        this.graph = graph;
        int n = graph.length;
        nodeStates = new State[n];
        Arrays.fill(nodeStates, State.UNVISITED);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (dfs(i)) {
                res.add(i);
            }
        }
        return res;
    }

    private boolean dfs(int i) {
        if (nodeStates[i] != State.UNVISITED) {
            return nodeStates[i] == State.SAFE;
        }
        nodeStates[i] = State.VISITING;
        for (int j : graph[i]) {
            if (!dfs(j)) {
                return false;
            }
        }
        nodeStates[i] = State.SAFE;
        return true;
    }
}
// @lc code=end

