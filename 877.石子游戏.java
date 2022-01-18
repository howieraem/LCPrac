/*
 * @lc app=leetcode.cn id=877 lang=java
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
    public boolean stoneGame(int[] piles) {
        // 1. As sum(piles) % 2 != 0, there will not be draw.
        // 2. As len(piles) % 2 == 0, one will always win, no matter who starts first.
        return true;
    }
}
// @lc code=end

