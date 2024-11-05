/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
    // T: O(log(n))
    // S: O(1)
    public int[] searchRange(int[] nums, int target) {
        int[] result = new int[2];
        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);
        return result;
    }
    
    private int findFirst(int[] nums, int target) {
        int idx = -1;
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            int m = l + ((r - l) >>> 1);
            if (nums[m] >= target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
            if (nums[m] == target) {
                idx = m;
            }
        }
        return idx;
    }
    
    private int findLast(int[] nums, int target) {
        int idx = -1;
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            int m = l + ((r - l) >>> 1);
            if (nums[m] <= target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
            if (nums[m] == target) {
                idx = m;
            }
        }
        return idx;
    }
}
// @lc code=end

