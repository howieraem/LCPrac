/*
 * @lc app=leetcode id=1834 lang=java
 *
 * [1834] Single-Threaded CPU
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n * log(n))
    // S: O(n)
    public int[] getOrder(int[][] tasks) {
        final int n = tasks.length;
        int[][] allTasks = new int[n][3];
        for (int i = 0; i < n; ++i) {
            allTasks[i][0] = i;
            allTasks[i][1] = tasks[i][0];
            allTasks[i][2] = tasks[i][1];
        }

        // sort by enqueue time
        Arrays.sort(allTasks, (a, b) -> Integer.compare(a[1], b[1]));

        // Compare process time and then the original indices of the tasks
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> a[2] == b[2] ? Integer.compare(a[0], b[0]) : Integer.compare(a[2], b[2]));
        int curTime = 0;
        int[] res = new int[n];
        int taskIdx = 0, resIdx = 0;
        while (resIdx < n) {
            while (taskIdx < n && allTasks[taskIdx][1] <= curTime) {
                pq.offer(allTasks[taskIdx++]);
            }

            if (pq.isEmpty()) {
                // Idle after a task is done (next enqueue time > current finish time), 
                // process the next task available.
                curTime = allTasks[taskIdx][1];
                continue;
            }

            int[] selectedTask = pq.poll();
            res[resIdx++] = selectedTask[0];
            curTime += selectedTask[2];
        }
        return res;
    }
}
// @lc code=end

