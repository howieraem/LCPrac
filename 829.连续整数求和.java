/*
 * @lc app=leetcode.cn id=829 lang=java
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
    /** 
     * As the numbers must be consecutive, they form an arithmetic progression (sequence).
     * The sum of the progression is:
     *      n = x * i + (i - 1) * i / 2
     * where x is the first number and i is the length of progression. After rearranging: 
     *      x = (n - (i - 1) * i / 2) / i
     *      i * (2 * x + i - 1) = 2 * n
     * Since x > 0 and i > 0, 2 * x + i - 1 > i, i ^ 2 < 2 * n.
     * Thus, the upper bound of i is sqrt(2 * n).
     */
    public int consecutiveNumbersSum(int n) {
        // Initialize answer as 1 instead of 0 and iterate from 2, 
        // because the base case is the number itself
        int ans = 1;    

        double upper = Math.sqrt(2 * n);
        for (int i = 2; i < upper; ++i) {
            // Count the number of valid integers x
            if ((n - i * (i - 1) / 2) % i == 0)  ++ans;
        }
        return ans;
    }
}
// @lc code=end

