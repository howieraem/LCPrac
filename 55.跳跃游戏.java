/*
 * @lc app=leetcode.cn id=55 lang=java
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
    public boolean canJump(int[] nums) {
        final int n = nums.length;
        int furthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            furthest = Math.max(furthest, i + nums[i]);
            if (furthest <= i)  return false;
        }
        return furthest >= n - 1;
    }
}
// @lc code=end

