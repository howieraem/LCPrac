/*
 * @lc app=leetcode.cn id=169 lang=java
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
    public int majorityElement(int[] nums) {
        int cnt = 1, major = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == major)  ++cnt;
            else if (--cnt == 0) {
                cnt = 1;
                major = nums[i];
            }
        }
        return major;
    }
}
// @lc code=end

