/*
 * @lc app=leetcode.cn id=231 lang=java
 *
 * [231] 2的幂
 */

// @lc code=start
class Solution {
    /** 
     * 解释：2 的幂次方在二进制下，只有 1 位是 1，其余全是 0。
     * 例如: 8 = 0b00001000。负数的在计算机中二进制表示为补码(原码->正常二进制表示，原码按位取反(0->1, 1->0)，最后再 +1。
     * 然后两者进行与操作，得到的肯定是原码中最后一个二进制的 1。例如 8 & (-8) = 0b00001000 & 0b11111000 = 0b00001000 = 8。
     */
    public boolean isPowerOfTwo(int n) {
        return (n > 0) && (n & -n) == n;
    }
}
// @lc code=end

