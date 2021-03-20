/*
 * @lc app=leetcode.cn id=201 lang=java
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        /* 对范围内所有数字执行按位与运算的
        结果是所有对应二进制字符串的公共前缀
        再用零补上后面的剩余位。

        Time: O(log(n))
        Space: O(1)
        */
        while (m < n) {
            n &= n - 1;     // erases the rightmost bit 1
        }
        return n;
    }
}
// @lc code=end

