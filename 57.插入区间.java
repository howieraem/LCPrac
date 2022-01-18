/*
 * @lc app=leetcode.cn id=57 lang=java
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // Different from q56, ``intervals`` already sorted.
        int start = 0, end = intervals.length - 1;
        int left = Integer.MIN_VALUE, right = Integer.MIN_VALUE;
        int[][] res;

        // Find the left of the new merged interval
        while (start <= end) {
            if (newInterval[0] <= intervals[start][1]) {
                left = Math.min(intervals[start][0], newInterval[0]);
                break;
            } else {
                ++start;
            }
        }
        if (left == Integer.MIN_VALUE) {
            // left not found, newInterval[0] is greater than all intervals' right.
            res = new int[intervals.length+1][2];
            System.arraycopy(intervals, 0, res, 0, intervals.length);
            res[intervals.length] = newInterval;
            return res;
        }

        // Find the right of the new merged interval
        while (start <= end) {
            if (newInterval[1] >= intervals[end][0]) {
                right = Math.max(intervals[end][1], newInterval[1]);
                break;
            } else {
                --end;
            }
        }
        if (right == Integer.MIN_VALUE) {
            // right not found but left found, newInterval should be placed at start.
            res = new int[intervals.length+1][2];
            System.arraycopy(intervals, 0, res, 0, start);
            System.arraycopy(intervals, start, res, start + 1, intervals.length - start);
            res[start] = newInterval;
            return res;
        }

        // both left and right found, create a new merged interval 
        // and copy the non-overlapping rest.
        res = new int[intervals.length-(end-start)][2];
        if (start > 0)  
            // if the new interval include the first one in original intervals, don't copy
            System.arraycopy(intervals, 0, res, 0, start);
        if (end + 1 <= intervals.length - 1)
            // if the new interval include the last one in original intervals, don't copy
            System.arraycopy(intervals, end + 1, res, start + 1, res.length - start - 1);
        res[start] = new int[] {left, right};
        return res;
    }
}
// @lc code=end

