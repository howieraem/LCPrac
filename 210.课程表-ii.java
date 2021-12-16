/*
 * @lc app=leetcode.cn id=210 lang=java
 *
 * [210] 课程表 II
 */
import java.util.*;


// @lc code=start
class Solution {
    // T: O(V+E), V := the number of nodes, E := the number of edges
    // S: O(V)
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // Modified from Q207. The difference here is that 
        // the topological sort result is required.

        // Get the in-degree and adjacency of every course.
        int[] inDegrees = new int[numCourses];
        List<List<Integer>> adjacency = new ArrayList<>();
        for (int i=0; i<numCourses; ++i) {
            adjacency.add(new ArrayList<>());
        }
        for (int[] edges: prerequisites) {
            inDegrees[edges[0]]++;
            adjacency.get(edges[1]).add(edges[0]);
        }

        // Get all the courses with zero in-degree.
        Queue<Integer> q = new LinkedList<>();
        for (int i=0; i<inDegrees.length; ++i) {
            if (inDegrees[i] == 0)  q.add(i);
        }

        // BFS topological sort
        int[] result = new int[numCourses];
        int idx = 0;
        while (!q.isEmpty()) {
            int pre = q.poll();
            // Add visited course to result array
            result[idx++] = pre;
            for (int cur: adjacency.get(pre)) {
                if (--inDegrees[cur] == 0)  q.add(cur);
            }
        }
        // Return empty result if loop found
        return idx != numCourses ? new int[0] : result;
    }
}
// @lc code=end

