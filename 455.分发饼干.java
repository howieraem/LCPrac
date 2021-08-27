import java.util.*;
/*
 * @lc app=leetcode.cn id=455 lang=java
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int ans = 0, cookie = 0;
        while (ans < g.length && cookie < s.length) {
            if (g[ans] <= s[cookie]) {
                ++ans;
            } // else current cookie does not satisfy
            ++cookie;
        }
        return ans;
    }
}
// @lc code=end

