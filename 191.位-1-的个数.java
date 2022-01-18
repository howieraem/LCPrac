/*
 * @lc app=leetcode.cn id=191 lang=java
 *
 * [191] 位1的个数
 */

// @lc code=start
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans = 0;
        while (n != 0) {
            ++ans;
            /* This will negate the current least significant 1, 
            while keeping the more significant bits on the left.
            */
            n &= (n - 1);   
        }
        return ans;
    }
}
// @lc code=end

