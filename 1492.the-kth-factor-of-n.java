/*
 * @lc app=leetcode id=1492 lang=java
 *
 * [1492] The kth Factor of n
 */

// @lc code=start
class Solution {
    public int kthFactor(int n, int k) {
        final int sqrt = (int) Math.sqrt(n) + 1;
        int i = 1;
        while (i < sqrt) {
            if (n % i == 0 && --k == 0) {
                return i;
            }
            ++i;
        }
        --i;
        if (i * i == n)  --i;   // special case: factor == sqrt(n), avoid double counting

        // When i < sqrt(n), n / i > i, the order is preserved, 
        // so continue decrementing k.
        while (i >= 1) {
            if (n % i == 0 && --k == 0) {
                return n / i;
            }
            --i;
        }
        return -1;
    }
}
// @lc code=end

