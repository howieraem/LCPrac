/*
 * @lc app=leetcode.cn id=207 lang=java
 *
 * [207] 课程表
 */
import java.util.*;

// @lc code=start
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
        while (q.size() != 0) {
            int pre = q.poll();  // pop left
            numCourses--;
            for (int cur: adjacency.get(pre)) {
                if (--inDegrees[cur] == 0)  q.add(cur);
            }
        }

        return numCourses == 0;
    }
}
// @lc code=end

