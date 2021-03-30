/*
 * @lc app=leetcode.cn id=190 lang=java
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
public class Solution {
    // 1. You need treat n as an unsigned value
    // 2. Works for 32-bit data only 
    public int reverseBits(int n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = (ans << 1) + (n & 1);
            n >>= 1;
        }
        return ans;
    }
}
// @lc code=end

