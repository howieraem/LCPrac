/*
 * @lc app=leetcode.cn id=540 lang=java
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int l = 0, r = nums.length - 1, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (mid % 2 == 1)  --mid;   // keep `mid` an even index number
            if (nums[mid] == nums[mid + 1]) {
                // `nums[mid]` is a number that appears twice
                l = mid + 2;    
            } else {
                // the number that appears once is on the left
                r = mid;
            }
        }
        // if `l == r`, then the target is found.
        return nums[l];
    }
}
// @lc code=end

