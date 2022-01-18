/*
 * @lc app=leetcode.cn id=7 lang=java
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        int ans = 0;
        final int preMax = Integer.MAX_VALUE / 10, 
                  preMin = Integer.MIN_VALUE / 10, 
                  preMaxRemainder = Integer.MAX_VALUE % 10,
                  preMinRemainder = Integer.MIN_VALUE % 10;
        while (x != 0) {
            int pop = x % 10;
            // look ahead for potential overflow
            if ((ans > preMax || (ans == preMax && pop > preMaxRemainder)) ||
                (ans < preMin || (ans == preMin && pop < preMinRemainder))) {
                return 0;
            }

            ans = ans * 10 + pop;
            x /= 10;
        }
        return ans;
    }
}
// @lc code=end
