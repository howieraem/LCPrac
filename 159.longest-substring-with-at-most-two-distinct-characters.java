/*
 * @lc app=leetcode id=159 lang=java
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 */
import java.util.*;

// @lc code=start
class Solution {
    // Sliding window
    // T: O(n)
    // S: O(alpha_sz)
    public int lengthOfLongestSubstringTwoDistinct(String s) {
        Map<Character, Integer> freqs = new HashMap<>();
        int l = 0;
        int windowCharTypeCnt = 0;
        int ans = 0;
        for (int r = 0; r < s.length(); ++r) {
            char c = s.charAt(r);
            freqs.put(c, freqs.getOrDefault(c, 0) + 1);
            if (freqs.get(c) == 1) {
                // new char type in window
                ++windowCharTypeCnt;
            }

            while (windowCharTypeCnt > 2) {
                char cLeft = s.charAt(l);
                freqs.put(cLeft, freqs.get(cLeft) - 1);
                if (freqs.get(cLeft) == 0) {
                    --windowCharTypeCnt;
                }
                ++l;
            }

            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
// @lc code=end

