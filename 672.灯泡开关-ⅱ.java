/*
 * @lc app=leetcode.cn id=672 lang=java
 *
 * [672] 灯泡开关 Ⅱ
 */

// @lc code=start
class Solution {
    /**
     * See explanation:
     * https://leetcode-cn.com/problems/bulb-switcher-ii/solution/wei-shi-yao-qian-san-ge-deng-pao-jiu-ke-yi-que-din/
     */
    public int flipLights(int n, int m) {
        switch (n) {
            case 0:  return 0;
            case 1:  return m > 0 ? 2 : 1;
            case 2:  return (m > 1 ? 1 : 0) + (m > 0 ? 2 : 0) + 1;
        }
        switch (m) {
            case 0:  return 1;
            case 1:  return 4;
            case 2:  return 7;
        }
        return 8;
    }
}
// @lc code=end

