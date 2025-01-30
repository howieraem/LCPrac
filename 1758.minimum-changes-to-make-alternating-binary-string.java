/*
 * @lc app=leetcode id=1758 lang=java
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution {
    // Array + Greedy?
    // T: O(n)
    // S: O(1)
    public int minOperations(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) - '0' != (i & 1)) {
                // Suppose we want a sequence like '0101...'
                // The indexes of zeros are odd, and the indexes of ones are even.
                ++ans;
            }
        }

        // Check which takes less changes, '01...' or '10...'
        return Math.min(ans, s.length() - ans);
    }
}
// @lc code=end

