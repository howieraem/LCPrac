import java.util.*;
/*
 * @lc app=leetcode.cn id=802 lang=java
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
    // public List<Integer> eventualSafeNodes(int[][] graph) {
    //     // A node is safe if either its out degree is 0, or nodes it points to are safe.
    //     // So reverse all edge directions and try topological sort.
    //     int n = graph.length;
    //     int[] inDeg = new int[n];
    //     List<List<Integer>> A = new ArrayList<>();
    //     for (int i = 0; i < n; ++i) {
    //         A.add(new ArrayList<>());
    //     }
    //     for (int i = 0; i < n; ++i) {
    //         for (int j : graph[i]) {
    //             A.get(j).add(i);
    //         }
    //         inDeg[i] += graph[i].length;
    //     }

    //     Queue<Integer> q = new ArrayDeque<>();
    //     for (int i = 0; i < n; ++i) {
    //         if (inDeg[i] == 0)  q.add(i);
    //     }

    //     while (!q.isEmpty()) {
    //         int u = q.poll();
    //         // One can collect valid u here too, but
    //         // needs further sorting at O(NlogN) which
    //         // is less efficient than finding zero
    //         // in-degree later at O(N).
    //         for (int v : A.get(u)) {
    //             if (--inDeg[v] == 0)  q.add(v);
    //         }
    //     }
        
    //     List<Integer> res = new ArrayList<>();
    //     for (int i = 0; i < n; ++i) {
    //         if (inDeg[i] == 0)  res.add(i);
    //     }
    //     return res;
    // }

    private static enum State {
        UNVISITED,
        VISITED,
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
            if (isSafe(i))  res.add(i);
        }
        return res;
    }

    private boolean isSafe(int i) {
        if (nodeStates[i] != State.UNVISITED) {
            return nodeStates[i] == State.SAFE;
        }
        nodeStates[i] = State.VISITED;
        for (int j : graph[i]) {
            if (!isSafe(j))  return false;
        }
        nodeStates[i] = State.SAFE;
        return true;
    }
}
// @lc code=end

