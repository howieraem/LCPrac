/*
 * @lc app=leetcode.cn id=1375 lang=java
 *
 * [1375] 灯泡开关 III
 */

// @lc code=start
class Solution {
    public int numTimesAllBlue(int[] light) {
        int ans = 0, rightmost = -1;
        for (int i = 0; i < light.length; ++i) {
            rightmost = Math.max(rightmost, light[i]);
            // If the index of rightmost bulb turned on equals to
            // the number of bulbs turned on, then all bulbs on
            // are blue. 
            if (rightmost == i + 1)  ++ans;
        }
        return ans;
    }
}
// @lc code=end

