/*
 * @lc app=leetcode.cn id=7 lang=java
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        int ans = 0;
        int preMax = Integer.MAX_VALUE / 10, preMin = Integer.MIN_VALUE / 10;
        while (x != 0) {
            int pop = x % 10;
            // look ahead for potential overflow
            if ((ans > preMax || (ans == preMax && pop > 7)) ||     // 7 是 2^31 - 1 的个位
                (ans < preMin || (ans == preMin && pop < -8))) {    // 8 是 -2^31 的个位
                return 0;
            }

            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
}
// @lc code=end
