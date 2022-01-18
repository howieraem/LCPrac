import java.util.*;
/*
 * @lc app=leetcode id=56 lang=java
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
    // T: O(n * log(n)), n := len(intervals)
    // S: O(1) ignoring the result container
    public int[][] merge(int[][] intervals) {
        final int n = intervals.length;
        if (n < 2)  return intervals;
        // Sort intervals by start ASC
        Arrays.sort(intervals, (inter1, inter2) -> inter1[0] - inter2[0]);

        int[][] res = new int[n][2];
        int start = intervals[0][0], end = intervals[0][1], p = 0;
        for (int i = 1; i < n; ++i) {
            // intervals are already sorted by start, so no need to compare start
            if (intervals[i][0] > end) {
                // no overlap, a new interval
                res[p++] = new int[]{start, end};
                start = intervals[i][0];
                end = intervals[i][1];
            } else if (intervals[i][1] > end) {
                // overlap, extend right boundary of current interval
                end = intervals[i][1];
            }
        }
        res[p++] = new int[]{start, end}; // don't forget the final interval

        return Arrays.copyOfRange(res, 0, p);
    }
}
// @lc code=end

