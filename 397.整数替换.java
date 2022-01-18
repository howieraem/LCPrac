/*
 * @lc app=leetcode.cn id=397 lang=java
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
    public int integerReplacement(int n) {
        if (n == Integer.MAX_VALUE)  return 32;     // 防止越界
        int ans = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                // even number
                n >>= 1;
            } else {
                // 1、大于1的奇数格式为 0bXX01 或者 0bXX11，对于前一种格式 - 1，对于后一种格式 + 1。
                // 2、仅当二进制比特位只有两位 0b11（十进制等于3）的时候，应 - 1
                n += ((n & 2) == 0 || n == 3) ? -1 : 1;
                // 或将 + 1 的情况写成以下形式防止越界：
                // ```
                // n = n / 2 + 1;
                // ++ans;
                // ```
            }
            ++ans;
        }
        return ans;
    }
}
// @lc code=end

