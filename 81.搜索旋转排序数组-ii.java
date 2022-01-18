/*
 * @lc app=leetcode.cn id=81 lang=java
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
    public boolean search(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)  return true;
            if (nums[l] == nums[m]) {
                // With duplicates, cannot determine which interval is ascending
                ++l;
            } else if (nums[m] <= nums[r]) {
                // right interval is ascending
                if (target > nums[m] && target <= nums[r])  l = m + 1;
                else  r = m - 1;
            } else {
                // nums[m] > nums[r], left interval is ascending
                if (target >= nums[l] && target < nums[m])  r = m - 1;
                else  l = m + 1;
            }
        }
        return false;
    }
}
// @lc code=end

