/*
 * @lc app=leetcode.cn id=438 lang=java
 *
 * [438] 找到字符串中所有字母异位词
 */
import java.util.*;

// @lc code=start
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int[] req = new int[26], win = new int[26];
        int reqChTypes = 0;
        for (int i = 0; i < p.length(); ++i) {
            int cIdx = (int) (p.charAt(i) - 'a');
            if (req[cIdx] == 0)  ++reqChTypes;
            ++req[cIdx];
        }

        int l = 0, r = 0, validChTypes = 0;
        List<Integer> res = new ArrayList<>();
        while (r < s.length()) {
            // Expand window to the right
            int cIdx = (int) (s.charAt(r) - 'a');
            ++r;
            if (req[cIdx] > 0) {
                ++win[cIdx];
                if (win[cIdx] == req[cIdx])  ++validChTypes;
            }

            while (r - l >= p.length()) {
                if (validChTypes == reqChTypes) {
                    res.add(l);
                }

                // Try shrinking window by moving the left pointer,
                // then update the counts.
                int cIdxD = (int) (s.charAt(l) - 'a');
                ++l;
                if (req[cIdxD] > 0) {
                    if (win[cIdxD] == req[cIdxD])  --validChTypes;
                    --win[cIdxD];
                }
            }
        }
        return res;
    }
}
// @lc code=end

