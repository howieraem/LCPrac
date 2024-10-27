/*
 * @lc app=leetcode.cn id=201 lang=java
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
    // Find the longest common prefix of m and n
    // because all numbers in between also share 
    // the same binary prefix.
    // T: O(log(n))
    // S: O(1)
    public int rangeBitwiseAnd(int m, int n) {
        // 对范围内所有数字执行按位与运算的结果
        // 是所有对应二进制字符串的公共前缀再用
        // 0补上后面的剩余位。
        while (m < n) {
            n &= n - 1;     // erases the rightmost bit 1 of n
        }
        return n;
    }
}
// @lc code=end

