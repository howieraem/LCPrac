import java.util.Set;
import java.util.HashSet;

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> occluded = new HashSet<>();
        int n = s.length(), j = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                occluded.remove(s.charAt(i-1));
            }
            while (j < n - 1 && !occluded.contains(s.charAt(j+1))) {
                occluded.add(s.charAt(++j));
            }
            ans = Math.max(ans, j - i + 1);
        }
        return ans;
    }
}
// @lc code=end

