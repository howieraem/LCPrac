/*
 * @lc app=leetcode.cn id=33 lang=java
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] == target)  return m;
            if (nums[l] <= nums[m]) {
                // nums[l, ..., m] is sorted
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {    // target > nums[m]
                    l = m + 1;
                }
            } else {
                // nums is rotated at somewhere within nums[l, ..., m]
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {    // target < nums[m]
                    r = m - 1;
                }
            }
        }
        return -1;
    }
}
// @lc code=end

