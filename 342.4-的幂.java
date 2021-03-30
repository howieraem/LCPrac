/*
 * @lc app=leetcode.cn id=342 lang=java
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
    // private static final double BASE = Math.log(2);

    // public boolean isPowerOfFour(int n) {
    //     return (n > 0) && ((Math.log(n) / BASE) % 2 == 0);
    // }

    public boolean isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0)   // whether n is power of 2
            && (n % 3 == 1);    // whether power is an even number
    }
}
// @lc code=end
