/*
 * @lc app=leetcode.cn id=80 lang=java
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 1, cnt = 1;
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i - 1])  ++cnt;
            else  cnt = 1;

            if (cnt <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
}
// @lc code=end

