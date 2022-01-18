/*
 * @lc app=leetcode.cn id=153 lang=java
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right]) {
                // not sorted, shift the left boundary          
                left = mid + 1;
            } else {
                // nums[mid:right+1] is sorted without duplicates               
                right = mid;
            }
        }
        return nums[left];
    }
}
// @lc code=end

