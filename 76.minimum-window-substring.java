/*
 * @lc app=leetcode id=76 lang=java
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
    // Sliding window
    // T: O(len(s) + len(s))
    // S: O()
    public String minWindow(String s, String t) {
        // The question is asking for the minimum window size such that all char types in t are involved.
        // Since t can contain duplicate chars, can't return false if len(t) > len(s)

        // The strings have both uppercase and lowercase, so use an array of 128 (the number of ASCII char types)
        // to record the char frequency without having to subtract 'a' etc.
        int[] requiredCharCnts = new int[128];
        for (char c : t.toCharArray()) {
            ++requiredCharCnts[c];
        }

        int nInvolvedCharTypes = 0;
        int ansBeginIdx = 0, ansLen = Integer.MAX_VALUE;
        char[] sa = s.toCharArray();
        for (int l = 0, r = 0; r < sa.length; ++r) {
            if (requiredCharCnts[sa[r]] > 0) {
                ++nInvolvedCharTypes;
            }
            requiredCharCnts[sa[r]]--;
            
            // Shift left boundary to minimize window size as much as possible
            while (nInvolvedCharTypes == t.length()) {
                int candidateLen = r - l + 1;
                if (ansLen > candidateLen) {
                    ansLen = candidateLen;
                    ansBeginIdx = l;
                }

                if (++requiredCharCnts[sa[l++]] > 0) {
                    --nInvolvedCharTypes;
                }
            }
        }
        return ansLen < Integer.MAX_VALUE ? s.substring(ansBeginIdx, ansBeginIdx + ansLen) : "";
    }
}
// @lc code=end

