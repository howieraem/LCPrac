/*
 * @lc app=leetcode.cn id=326 lang=java
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution {
    /** Solution for any positive number */
    // public boolean isPowerOfThree(int n) {
    //     if (n < 1)  return false;
    //     while (n % 3 == 0) {
    //         n /= 3;
    //     }
    //     return n == 1;
    // }

    /** Solution for n <= Integer.MAX_VALUE only */
    // MAX_CASE = 3 ^ floor(log3(2 ^ 31 - 1)) = 3 ^ 19
    private static final int MAX_CASE = 1162261467;  
    // (int) Math.pow(3, Math.floor(Math.log(Integer.MAX_VALUE) / Math.log(3)));

    public boolean isPowerOfThree(int n) {
        return n > 0 && MAX_CASE % n == 0;
    }
}
// @lc code=end

