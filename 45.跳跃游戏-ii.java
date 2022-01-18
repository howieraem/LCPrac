/*
 * @lc app=leetcode.cn id=45 lang=java
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
    public int jump(int[] nums) {
        int n = nums.length, rightmost = 0, steps = 0, end = 0;
        for (int i = 0; i < n - 1; ++i) {
            rightmost = Math.max(rightmost, i+nums[i]);
            if (i == end) {
                end = rightmost;
                ++steps;
            }
        }
        return steps;
    }
}
// @lc code=end

