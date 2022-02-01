/*
 * @lc app=leetcode id=253 lang=java
 *
 * [253] Meeting Rooms II
 */
import java.util.*;

// @lc code=start
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        final int n = intervals.length;
        int[] start = new int[n], end = new int[n];
        for (int i = 0; i < n; ++i) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        Arrays.sort(start);
        Arrays.sort(end);
        int rooms = 0, endId = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] < end[endId]) {
                ++rooms;    // overlap - need a new room
            } else {
                // no overlap - the current interval can reuse an existing room
                ++endId;
            }
        }
        return rooms;
    }
}
// @lc code=end

