/*
 * @lc app=leetcode.cn id=292 lang=java
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
    public boolean canWinNim(int n) {
        // To win, the last iteration should have 1-3 stones left,
        // so the second last iteration must have 4 stones left.
        // In order to achieve this, in the former step there
        // must be 5-7 stones left. 8 stones left will definitely
        // lead to 5-7 stones in the next step.
        // Therefore, it can be found that if n is divisible by 4,
        // the player loses, otherwise wins.
        return n % 4 != 0;
    }
}
// @lc code=end

