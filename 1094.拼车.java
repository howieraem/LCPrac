/*
 * @lc app=leetcode.cn id=1094 lang=java
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
    private static final int MAX_STOPS = 1000;

    // 差分数组法
    public boolean carPooling(int[][] trips, int capacity) {
        // If MAX_STOPS not known, use an ordered map instead
        int[] d = new int[MAX_STOPS + 1];

        // Record the net people getting on car
        // (get on - get off) at each stop
        for (int i = 0; i < trips.length; ++i) {
            d[trips[i][1]] += trips[i][0];
            d[trips[i][2]] -= trips[i][0];
        }

        // Since both trip start and end are monotonic (one direction),
        // sum the net people getting on up and check if exceed
        int cur = 0;
        for (int i = 0; i < 1001; ++i) {
            if ((cur += d[i]) > capacity) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

