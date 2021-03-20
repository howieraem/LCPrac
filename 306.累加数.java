/*
 * @lc app=leetcode.cn id=306 lang=java
 *
 * [306] 累加数
 */

// @lc code=start
class Solution {
    private String s;
    private int n;

    public boolean isAdditiveNumber(String num) {
        s = num;
        n = num.length();
        return helper(0, 0, 0, 0);
    }

    private boolean helper(int idx, long sum, long pre, int cnt) {
        if (idx == n) {
            return cnt >= 3;
        }
        long val = 0;
        for (int i = idx; i < n; ++i) {
            if (i > idx && s.charAt(idx) == '0')  break;
            val = val * 10 + s.charAt(i) - '0';
            if (cnt >= 2) {
                if (val < sum)  continue;
                else if (val > sum)  break;
            }
            if (helper(i + 1, pre + val, val, cnt + 1))  return true;
        }
        return false;
    }
}
// @lc code=end

