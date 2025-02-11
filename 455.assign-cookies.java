/*
 * @lc app=leetcode id=455 lang=java
 *
 * [455] Assign Cookies
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // Sorting + two pointers
    // T: O(n * log(n))
    // S: O(sorting)
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        
        int i = 0;
        int j = 0;
        while (i < g.length && j < s.length) {
            if (g[i] <= s[j]) {
                ++i;
            }
            ++j;
        }

        return i;
    }
}
// @lc code=end

