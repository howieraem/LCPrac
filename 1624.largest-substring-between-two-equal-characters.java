/*
 * @lc app=leetcode id=1624 lang=java
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    // Hash Map
    // T: O(n + alpha_size)
    // S: O(alpha_size)
    public int maxLengthBetweenEqualCharacters(String s) {
        int[] charFirstIdx = new int[26];
        Arrays.fill(charFirstIdx, -1);

        int ans = -1;
        for (int i = 0; i < s.length(); ++i) {
            int cidx = s.charAt(i) - 'a';
            if (charFirstIdx[cidx] == -1) {
                charFirstIdx[cidx] = i;
            } else {
                ans = Math.max(ans, i - charFirstIdx[cidx] - 1);
            }
        }

        return ans;
    }
}
// @lc code=end

