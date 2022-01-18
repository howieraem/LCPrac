/*
 * @lc app=leetcode.cn id=810 lang=java
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution {
    public boolean xorGame(int[] nums) {
        if (nums.length % 2 == 0)  return true;
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        return xor == 0;
    }
}
// @lc code=end

