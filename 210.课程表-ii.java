/*
 * @lc app=leetcode.cn id=210 lang=java
 *
 * [210] 课程表 II
 */
import java.util.*;


// @lc code=start
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // actual question: is `prerequisites` a DAG (directed graph without loop)?
        // approach: use topological sort.
        int[] inDegrees = new int[numCourses];
        List<List<Integer>> adjacency = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for (int i=0; i<numCourses; ++i) {
            adjacency.add(new ArrayList<>());
        }

        // Get the in-degree and adjacency of every course.
        for (int[] edges: prerequisites) {
            inDegrees[edges[0]]++;
            adjacency.get(edges[1]).add(edges[0]);
        }

        // Get all the courses with zero in-degree.
        for (int i=0; i<inDegrees.length; ++i) {
            if (inDegrees[i] == 0)  q.add(i);
        }

        // BFS topological sort
        int[] result = new int[numCourses];
        int idx = 0;
        while (!q.isEmpty()) {
            int pre = q.poll();  // pop left
            result[idx++] = pre;
            for (int cur: adjacency.get(pre)) {
                if (--inDegrees[cur] == 0)  q.add(cur);
            }
        }
        if (idx != numCourses)  return new int[0];
        return result;
    }
}
// @lc code=end

