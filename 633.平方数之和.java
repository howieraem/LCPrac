/*
 * @lc app=leetcode.cn id=633 lang=java
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
    public boolean judgeSquareSum(int c) {
        int l = 0, r = (int) Math.sqrt(c);
        while (l <= r) {
            int diff = c - r * r;   // avoid overflow of l^2 + r^2
            if (diff == l * l)  return true;
            else if (diff > l * l)  ++l;
            else --r;
        }
        return false;
    }
}
// @lc code=end

