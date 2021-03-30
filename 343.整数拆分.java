/*
 * @lc app=leetcode.cn id=343 lang=java
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
    /** 
     * 1. 若拆分的数量确定，则各拆分数字相等时，乘积最大
     * 2. 将数字尽可能以因子 `3` 等分时，乘积最大
     */
    public int integerBreak(int n) {
        if (n <= 3)  return n - 1;
        int a = n / 3, b = n % 3;
        switch (b) {
            case 0:
                return (int) Math.pow(3, a);
            case 1:
                // 2*2 = 4 > 1*3
                return (int) Math.pow(3, a - 1) * 4;
            default:
                return (int) Math.pow(3, a) * 2;
        }
    }
}
// @lc code=end

