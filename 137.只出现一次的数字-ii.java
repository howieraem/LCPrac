/*
 * @lc app=leetcode.cn id=137 lang=java
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
    public int singleNumber(int[] nums) {
        int seen1 = 0, seen2 = 0;
        for (int num : nums) {
            seen1 = ~seen2 & (seen1 ^ num);
            seen2 = ~seen1 & (seen2 ^ num);
        }
        return seen1;
    }
}
// @lc code=end

