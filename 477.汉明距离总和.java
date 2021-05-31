/*
 * @lc app=leetcode.cn id=477 lang=java
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution {
    public int totalHammingDistance(int[] nums) {
        int ans = 0;

        // Calculate the sum of hamming distances for each bit and 
        // sum them up (32 bits for int in Java)
        for (int i = 0; i < 31; ++i) {
            int[] bitCnt = new int[2];
            for (int j = 0; j < nums.length; ++j) {
                // count the rightmost bit every iter
                ++bitCnt[nums[j] & 1];
                nums[j] >>= 1;
            }
            // sum of hamming distances at current place = n_bit0 * n_bit1
            ans += bitCnt[0] * bitCnt[1];
        }
        return ans;
    }
}
// @lc code=end
