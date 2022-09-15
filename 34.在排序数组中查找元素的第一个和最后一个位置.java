/*
 * @lc app=leetcode.cn id=34 lang=java
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 0)  return new int[]{-1, -1};
        int lower = findLeftMost(nums, target);
        int upper = findRightMost(nums, target);
        if (lower == nums.length || nums[lower] != target) {
            return new int[]{-1, -1};
        }
        return new int[]{lower, upper};
    }

    private int findLeftMost(int[] nums, int target) {
        int l = 0, r = nums.length, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)  r = mid;
            else  l = mid + 1;
        }
        return l;
    }

    private int findRightMost(int[] nums, int target) {
        int l = 0, r = nums.length, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > target)  r = mid;
            else  l = mid + 1;
        }
        return l - 1;
    }
}
// @lc code=end

