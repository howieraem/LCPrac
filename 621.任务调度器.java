/*
 * @lc app=leetcode.cn id=621 lang=java
 *
 * [621] 任务调度器
 */

// @lc code=start
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int nt = tasks.length;
        int[] cnts = new int[26];
        int maxCnt = 0, nTasksAtMaxCnt = 0;
        for (int i = 0; i < nt; ++i) {
            char c = tasks[i];
            int cIdx = (int) (c - 'A');
            ++cnts[cIdx];
            if (cnts[cIdx] > maxCnt) {
                maxCnt = cnts[cIdx];
                nTasksAtMaxCnt = 1;
            } else if (cnts[cIdx] == maxCnt) {
                ++nTasksAtMaxCnt;
            }
        }

        // To reduce overall time, tasks occurring more should be handled first. 
        // Other tasks can be fit into the interval between the same kind of task.
        // Example to explain:
        //  - Suppose tasks = ['A', 'A', 'A', 'B', 'C'], n = 2
        //  - Optimal scheduling would be ['A', x, x, 'A', x, x, 'A'], where x can be idle or another kind of task
        //  - This gives the equation (n + 1) * (3 - 1) + 1 where the max count is 3 and only 1 task has the max count
        //  - This can be generalized to more than one tasks with the max count
        //  - Note that when n = 0, the equation will give a wrong answer. It should just return the number of tasks instead.
        return Math.max((n + 1) * (maxCnt - 1) + nTasksAtMaxCnt, nt);
    }
}
// @lc code=end

