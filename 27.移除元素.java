/*
 * @lc app=leetcode.cn id=27 lang=java
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0, n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[--n];
            } else {
                ++i;
            }
        }
        return n;
    }
}
// @lc code=end
