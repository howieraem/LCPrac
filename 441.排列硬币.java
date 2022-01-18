/*
 * @lc app=leetcode.cn id=441 lang=java
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
    // public int arrangeCoins(int n) {
    //     long l = 0, r = n;
    //     // Find the upper bound of rows
    //     while (l <= r) {
    //         long m = l + ((r - l) >> 1);
    //         if (sumArithSeq(m) > n) {
    //             r = m - 1;
    //         } else {
    //             l = m + 1;
    //         }
    //     }
    //     return (int) r;
    // }

    // // returns sum of [1, 2, ..., n]
    // private long sumArithSeq(long n) {
    //     return (n * (n + 1)) >> 1;
    // }

    // r * (r + 1) / 2 <= n, use the equation for solving quadratic equation 
    public static int arrangeCoins(int n) {
        return (int) (-1 + Math.sqrt(1 + 8 * (long) n)) >> 1;
    }
}
// @lc code=end

