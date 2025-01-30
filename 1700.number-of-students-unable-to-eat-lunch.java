/*
 * @lc app=leetcode id=1700 lang=java
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
    // Counter + Simulation
    // T: O(n)
    // S: O(1)
    public int countStudents(int[] students, int[] sandwiches) {
        int need_zeros = 0;
        int need_ones = 0;
        for (int s : students) {
            if (s == 0) {
                ++need_zeros;
            } else {
                ++need_ones;
            }
        }

        for (int s : sandwiches) {
            if (s == 0) {
                if (need_zeros == 0) {
                    // no more students need type 0,
                    // return no. of unserved students who need type 1.
                    return need_ones;
                }
                --need_zeros;
            } else {  // s == 1
                if (need_ones == 0) {
                    // no more students need type 1,
                    // return no. of unserved students who need type 0.
                    return need_zeros;
                }
                --need_ones;
            }
        }

        return 0;
    }
}
// @lc code=end

