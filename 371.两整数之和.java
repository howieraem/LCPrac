/*
 * @lc app=leetcode.cn id=371 lang=java
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
    public int getSum(int a, int b) {
        while (b != 0) {
            int tmp = a ^ b;    // 相加各位的值，不算进位
            b = /*in C++ need to cast as unsigned int*/(a & b) << 1;    // 算进位值并左移
            a = tmp;
        }
        return a;
    }
}
// @lc code=end

