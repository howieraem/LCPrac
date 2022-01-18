/*
 * @lc app=leetcode.cn id=915 lang=java
 *
 * [915] 分割数组
 */

// @lc code=start
class Solution {
    public int partitionDisjoint(int[] nums) {
        int maxLeft = nums[0], max = nums[0], idx = 0;
        for (int i = 1; i < nums.length; ++i) {
            max = Math.max(max, nums[i]);
            if (nums[i] < maxLeft) {
                maxLeft = max;
                idx = i;
            }
        }
        return idx + 1;
    }
}
// @lc code=end

