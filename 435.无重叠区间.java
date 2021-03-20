import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode.cn id=435 lang=java
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        return intervals.length - intervalSchedule(intervals);
    }

    /** 
     * Returns the number of non-overlapping intervals.
     * If an interval's right boundary equals the left
     * boundary of the next interval, then they are
     * considered non-overlapping. 
     */
    private int intervalSchedule(int[][] intervals) {
        if (intervals.length == 0)  return 0;
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b) {
                return a[1] - b[1];
            }
        });     // sort by the right boundary of each interval

        int cnt = 1;
        int pre_end = intervals[0][1];
        for (int[] interval : intervals) {
            if (interval[0] >= pre_end) {
                ++cnt;
                pre_end = interval[1];
            }
        }
        return cnt;
    }
}
// @lc code=end

