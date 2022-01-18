/*
 * @lc app=leetcode.cn id=279 lang=java
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
    /**
     * 问题的上界：
     *  1. 四平方数定理：正整数n可表示为4个正整数的平方和a^2 + b^2 + c^2 + d^2
     * 
     *  2. 三平方数定理：若正整数n不等于4^k * (8*m + 7)的形式，k和m为正整数，则n可表示为3个正整数的平方和
     * 
     */
    public int numSquares(int n) {
        if (isSq(n))  return 1;

        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7)  return 4;  // 不符合三平方数条件

        // 检查是否能分解为两个平方数的和，只能枚举
        for (int i = 0; i * i <= n; ++i) {
            if (isSq(n - i * i))  return 2;
        }

        return 3;   // 找不到两个平方数，只能为三个
    }

    /** 检查一个数是否为平方数 */
    private boolean isSq(int n) {
        int sq = (int) Math.sqrt(n);
        return sq * sq == n;
    }
}
// @lc code=end

