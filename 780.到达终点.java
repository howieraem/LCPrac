/*
 * @lc app=leetcode.cn id=780 lang=java
 *
 * [780] 到达终点
 */

// @lc code=start
class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        // time complexity O(log(max(tx, ty))) assuming mod operation is O(1), 
        // space complexity O(1)
        while (tx >= sx && ty >= sy) {
            // if (tx == ty) break;
            if (tx > ty) {
                if (ty > sy)  tx %= ty;
                else  return (tx - sx) % ty == 0;
            } else {
                if (tx > sx)  ty %= tx;
                else  return (ty - sy) % tx == 0;
            }
        }
        return tx == sx && ty == sy;
    }
}
// @lc code=end

