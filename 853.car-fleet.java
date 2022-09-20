/*
 * @lc app=leetcode id=853 lang=java
 *
 * [853] Car Fleet
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // T: O(n * log(n))
    // S: O(n)
    public int carFleet(int target, int[] position, int[] speed) {
        final int n = position.length;
        double[][] posAndTime = new double[n][2];
        for (int i = 0; i < n; ++i) {
            posAndTime[i] = new double[] {position[i], (double)(target - position[i]) / speed[i]};
        }
        
        // Sort by position
        Arrays.sort(posAndTime, (a, b) -> Double.compare(a[0], b[0]));

        // If a car needs more time to reach the target than some other cars,
        // it is slower and will become the lead of a car fleet.
        // Iterate backward to check which cars will be caught up.
        double curFleetNeedTime = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (posAndTime[i][1] > curFleetNeedTime) {
                ++ans;
                curFleetNeedTime = posAndTime[i][1];
            }
        }
        return ans;
    }
}
// @lc code=end

