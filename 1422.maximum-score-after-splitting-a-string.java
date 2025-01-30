/*
 * @lc app=leetcode id=1422 lang=java
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution {
    // Math + Array + Greedy?
    // T: O(n)
    // S: O(1)
    public int maxScore(String s) {
        /*
        One-pass approach:
            score = left_zeros + right_ones
                  = left_zeros + (total_ones - left_ones)
                  = left_zeros - left_ones + total_ones
        
        As total_ones is a constant, we need to maximize left_zeros - left_ones
        to maximize the score.
        */ 

        // running counts
        int zeros = 0;
        int ones = 0;
        int max_diff = Integer.MIN_VALUE;

        // IMPORTANT: max_diff not updated when i == n - 1
        // because the right substring cannot be empty.
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s.charAt(i) == '0') {
                ++zeros;
            } else {
                ++ones;
            }

            max_diff = Math.max(max_diff, zeros - ones);
        }

        // check last char
        if (s.charAt(s.length() - 1) == '1') {
            ++ones;
        }

        return max_diff + ones;
    }
}
// @lc code=end

