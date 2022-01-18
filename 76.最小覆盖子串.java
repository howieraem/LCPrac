/*
 * @lc app=leetcode.cn id=76 lang=java
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
    public String minWindow(String s, String t) {
        // 128 is the no. of ASCII chars
        int[] charCnts = new int[128];     
        boolean[] charExists = new boolean[128];

        for (int i = 0; i < t.length(); ++i) {
            char c = t.charAt(i);
            charExists[c] = true;
            ++charCnts[c];
        }

        int cnt = 0, l = 0, minL = 0, minSize = s.length() + 1;
        for (int r = 0; r < s.length(); ++r) {
            char cR = s.charAt(r);
            if (charExists[cR]) {
                if (--charCnts[cR] >= 0)  ++cnt;
                
                // If the current sliding window has contained all types of characters
                // in t, then try shifting the left pointer to the right to get a 
                // shorter substring.
                while (cnt == t.length()) {
                    if (r - l + 1 < minSize) {
                        // update the position of substring if shorter
                        minL = l;
                        minSize = r - l + 1;
                    }
                    char cL = s.charAt(l);
                    if (charExists[cL] && ++charCnts[cL] > 0) {
                        --cnt;
                    }
                    ++l;
                } 
            }
        }
        return minSize > s.length() ? "" : s.substring(minL, minL + minSize);
    }
}
// @lc code=end

