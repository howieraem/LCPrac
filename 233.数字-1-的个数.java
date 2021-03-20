/*
 * @lc app=leetcode.cn id=233 lang=java
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
    private static final int K = 1;  // the target digit to count

    public int countDigitOne(int n) {
        int cnt = 0; 
        long base = 1;

        while (base <= n) {
            // 从个位遍历至最大位数，第i位数的base = 10 ^ (i - 1)
            long cur = (n / base) % 10;     // digit at `log10(base) + 1`th place from the smallest digit
            long high = n / (base * 10);        // digits in front of `cur` (prefix)
            long low = n - n / base * base;     // digits at the back of `cur` (suffix)

            if (cur > K)  cnt += (high + 1) * base;
            else if (cur == K)  cnt += high * base + low + 1;
            else  cnt += high * base;

            base *= 10;
        }

        return cnt;
    }
}
// @lc code=end

