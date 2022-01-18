/*
 * @lc app=leetcode.cn id=91 lang=java
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
    public int numDecodings(String s) {
        char pre = s.charAt(0);
        if (pre == '0')  return 0;
        int dp0 = 1, dp1 = 1, dp2 = 0;

        for (int i = 1; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c != '0') {
                dp2 += dp1;
            }

            int cur = ((int) (pre - '0')) * 10 + (int) (c - '0');
            if (cur >= 10 && cur <= 26) {
                dp2 += dp0;
            }

            dp0 = dp1;
            dp1 = dp2;
            dp2 = 0;
            pre = c;
        }
        return dp1;
    }
}
// @lc code=end

