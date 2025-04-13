/*
 * @lc app=leetcode id=1052 lang=java
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution {
    // Sliding window
    // T: O(n)
    // S: O(1)
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        final int n = customers.length;

        int satisfied = 0;
        int windowedUnsatisfied = 0;
        int madeSatisfied = 0;
        for (int r = 0; r < n; ++r) {
            if (grumpy[r] == 0) {
                satisfied += customers[r];
            } else {
                windowedUnsatisfied += customers[r];
            }

            int l = r - minutes;
            if (l >= 0) {
                windowedUnsatisfied -= customers[l] * grumpy[l];
            }

            // maximize the number of currently unsatisfied customers that can be made satisfied
            madeSatisfied = Math.max(madeSatisfied, windowedUnsatisfied);
        }

        return satisfied + madeSatisfied;
    }
}
// @lc code=end

