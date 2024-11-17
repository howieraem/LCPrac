/*
 * @lc app=leetcode.cn id=1094 lang=java
 *
 * [1094] 拼车
 */

// @lc code=start
class Solution {
    private static final int MAX_STOPS = 1000;

    // sweeping line (variant?) + prefix sum
    // 差分数组法
    // T: O(MAX_STOPS) or O(n * log(n)) if using a sorted map
    // S: O(MAX_STOPS) or O(n) if using a sorted map
    public boolean carPooling(int[][] trips, int capacity) {
        // If MAX_STOPS not known, use a sorted map (std::map, TreeMap) instead
        int[] d = new int[MAX_STOPS + 1];  // k: stop id, v: passenger number net change

        // Record the net people getting on car
        // (get on - get off) at each stop
        for (int i = 0; i < trips.length; ++i) {
            d[trips[i][1]] += trips[i][0];  // at trip start, add no. of passengers
            d[trips[i][2]] -= trips[i][0];  // at trip end, subtract no. of passengers
        }

        // Since both trip start and end are monotonic (one direction),
        // sum the net people getting on up and check if exceed
        int cur = 0;
        for (int i = 0; i <= MAX_STOPS; ++i) {
            cur += d[i];
            if (cur > capacity) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

