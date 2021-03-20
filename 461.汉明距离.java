/*
 * @lc app=leetcode.cn id=461 lang=java
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
    public int hammingDistance(int x, int y) {
        int xor = x ^ y, ans = 0;
        // count the number of bit 1's in XOR(x, y)
        while (xor > 0) {
            // Brian Kernighan Algorithm: erases the rightmost bit 1
            xor &= xor - 1;
            ++ans;
        }
        return ans;
    }
}
// @lc code=end
