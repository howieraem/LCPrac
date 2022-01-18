/*
 * @lc app=leetcode.cn id=1629 lang=java
 *
 * [1629] 按键持续时间最长的键
 */

// @lc code=start
class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        char ans = keysPressed.charAt(0);
        int max = releaseTimes[0];

        for (int i = 1; i < keysPressed.length(); ++i) {
            char pressed = keysPressed.charAt(i);
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > max) {
                max = duration;
                ans = pressed;
            } else if (duration == max && pressed > ans) {
                ans = pressed;
            }
        }
        return ans;
    }
}
// @lc code=end

