/*
 * @lc app=leetcode id=1497 lang=java
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
class Solution {
    // Math + hash map
    // T: O(n + k)
    // S: O(k)
    public boolean canArrange(int[] arr, int k) {
        if (k <= 0) {
            return false;
        }
        int[] rem_freqs = new int[k];
        for (int x : arr) {
            int rem = x % k;
            if (rem < 0) {
                // for negative x, normalize remainder to range [0 ... k - 1]
                rem += k;
            }
            ++rem_freqs[rem];
        }

        // check special case: x's divisible by k
        if ((rem_freqs[0] & 1) != 0) {
            // odd number of x's divisible by k, one of which can't form a pair
            return false;
        }

        // check other x's
        for (int i = 1; i <= (k >> 1); ++i) {
            if (rem_freqs[i] != rem_freqs[k - i]) {
                // If a % k = i and b % k = k - i, then 
                // (a + b) % k = (a % k + b % k) % k = 0.
                return false;
            }
        }

        return true;
    }
}
// @lc code=end

