/*
 * @lc app=leetcode id=593 lang=java
 *
 * [593] Valid Square
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // T: O(1)
    // S: O(1)
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        if (Arrays.equals(p1, p2) && Arrays.equals(p2, p3) && Arrays.equals(p3, p4)) {
            // points are the same
            return false;
        }

        int[] dists = new int[] {
            dist(p1, p2),
            dist(p1, p3),
            dist(p1, p4),
            dist(p2, p3),
            dist(p2, p4),
            dist(p3, p4)
        };
        Arrays.sort(dists);

        if (dists[0] == dists[1] && dists[1] == dists[2] && dists[2] == dists[3]) {
            // 1. The shortest distances should be the same which form the sides of the square
            if (dists[4] == dists[5]) {
                // 2. The diagonals should have the same length
                return true;
            }
        }
        return false;
    }

    private static int dist(final int[] p1, final int[] p2) {
        int dx = p1[0] - p2[0], dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }
}
// @lc code=end

