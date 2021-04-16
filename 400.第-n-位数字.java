/*
 * @lc app=leetcode.cn id=400 lang=java
 *
 * [400] 第 N 位数字
 */

// @lc code=start
class Solution {
    private static final int[] LVL = new int[10];

    static {
        // LVL[0] = 0;
        LVL[1] = LVL[0] + 9;
        LVL[2] = LVL[1] + 90 * 2;
        LVL[3] = LVL[2] + 900 * 3;
        LVL[4] = LVL[3] + 9000 * 4;
        LVL[5] = LVL[4] + 90000 * 5;
        LVL[6] = LVL[5] + 900000 * 6;
        LVL[7] = LVL[6] + 9000000 * 7;
        LVL[8] = LVL[7] + 90000000 * 8;
        LVL[9] = Integer.MAX_VALUE;
    }

    public int findNthDigit(int n) {
        // Question: find the nth character (i.e. digit) in 
        // "123456789101112131415161718192021..."
        int len = 1, base = 1;
        while (LVL[len] < n) {
            ++len;
            base *= 10;
        }
        n -= LVL[len - 1];
        return n % len == 0 ? getPos(base + n / len - 1, len) : getPos(base + n / len, n % len);
    }

    private int getPos(int num, int i) {
        return Integer.toString(num).charAt(i - 1) - '0';
    }
}
// @lc code=end

