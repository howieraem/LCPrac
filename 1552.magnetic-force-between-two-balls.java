/*
 * @lc app=leetcode id=1552 lang=java
 *
 * [1552] Magnetic Force Between Two Balls
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // Sorting + Binary search
    // T: O(n * (log(n) + log(max(position) - min(position) / (x - 1))))
    // S: O(n) sorting
    public int maxDistance(int[] position, int x) {
        if (position.length <= 1) {
            return 0;
        }
        Arrays.sort(position);

        // binary search minimum distance between any two ball placements
        int l = 1;
        int r = (position[position.length - 1] - position[0]) / (x - 1);
        int ans = 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (canPlace(m, position, x)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

    private boolean canPlace(int dist, final int[] position, int x) {
        int lastPlaced = -1;
        for (int i = 0; i < position.length; ++i) {
            if (lastPlaced == -1 || lastPlaced + dist <= position[i]) {
                if (--x == 0) {
                    return true;
                }

                lastPlaced = position[i];
            }
        }
        return false;
    }
}
// @lc code=end

