/*
 * @lc app=leetcode id=1752 lang=java
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
    // Counter + Circular array
    // T: O(n)
    // S: O(1)
    public boolean check(int[] nums) {
        final int n = nums.length;
        int violates = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                ++violates;
                
                if (violates > 1) {
                    return false;
                }
            }
        }
        return true;
    }
}
// @lc code=end

