/*
 * @lc app=leetcode.cn id=154 lang=java
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (nums[m] > nums[r]) {
                // not sorted          
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                // nums[m:r+1] is sorted without duplicates                         
                r = m;
            } else {
                // Found equal, linearly move right until no duplicates
                --r;
            }
        }
        return nums[l];
    }
}
// @lc code=end

