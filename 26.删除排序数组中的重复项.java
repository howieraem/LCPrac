/*
 * @lc app=leetcode.cn id=26 lang=java
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0, j = 1;
        while (j < nums.length) {
            if (nums[j] == nums[i]) {
                j++;
            } else {
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
}
// @lc code=end

