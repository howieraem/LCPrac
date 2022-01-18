import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=1235 lang=java
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
    class Job {
        int start, end, profit;

        Job(int start, int end, int profit) {
            this.start = start;
            this.end = end;
            this.profit = profit;
        }
    }

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        Job[] jobs = new Job[n];
        for (int i = 0; i < n; ++i) {
            jobs[i] = new Job(startTime[i], endTime[i], profit[i]);
        }
        // sort jobs by end time
        Arrays.sort(jobs, Comparator.comparingInt(j -> j.end));

        int[] dp = new int[n];
        dp[0] = jobs[0].profit;  // base case
        for (int i = 1; i < n; ++i) {
            // Base case: select just the current job or the previous combination
            dp[i] = Math.max(dp[i - 1], jobs[i].profit);

            // Iterate to include more jobs
            for (int j = i - 1; j >= 0; --j) {
                if (jobs[j].end <= jobs[i].start) {
                    // Since jobs are sorted by end time, 
                    // find the closest previous job 
                    // without overlapping the current
                    dp[i] = Math.max(dp[i], jobs[i].profit + dp[j]);
                    break;
                }
            }
        }
        return dp[n - 1];
    }
}
// @lc code=end

