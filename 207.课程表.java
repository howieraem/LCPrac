/*
 * @lc app=leetcode.cn id=207 lang=java
 *
 * [207] 课程表
 */
import java.util.*;

// @lc code=start
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // Actual question: Do prerequisites form a DAG (Directed Acyclic Graph)?
        // Approach: use topological sort. 
        // Topological sort does not exist if there exist cycle(s).

        // Get the in-degree and adjacency of every course.
        int[] inDegrees = new int[numCourses];
        List<List<Integer>> adjacency = new ArrayList<>();
        for (int i = 0; i < numCourses; ++i) {
            adjacency.add(new ArrayList<>());
        }
        for (int[] edge : prerequisites) {
            inDegrees[edge[0]]++;
            adjacency.get(edge[1]).add(edge[0]);
        }

        // Separate all the courses (nodes) with zero in-degree.
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0)  q.add(i);
        }

        // BFS topological sort
        while (!q.isEmpty()) {
            int pre = q.poll();
            --numCourses;

            // If the topological sort result is needed, 
            // add `pre` to the result collection here

            for (int cur : adjacency.get(pre)) {
                // Decrement the in-degree of nodes to which the sperated node points.
                // If this causes the in-degree of this pointed node to be 0, 
                // enqueue it as well.
                if (--inDegrees[cur] == 0)  q.add(cur);
            }
        }

        return numCourses == 0;     // Whether all nodes are visited in topological sort process
    }
}
// @lc code=end

