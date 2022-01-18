/*
 * @lc app=leetcode.cn id=335 lang=java
 *
 * [335] 路径交叉
 */

// @lc code=start
class Solution {
    public boolean isSelfCrossing(int[] distance) {
        int n = distance.length;
        for (int i = 3; i < n; ++i) {
            if (i >= 3 && distance[i - 1] <= distance[i - 3] && distance[i] >= distance[i - 2]) {
                return true;
            }
            if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) {
                return true;
            }
            if (i >= 5 && distance[i - 2] > distance[i - 4] && distance[i - 3] > distance[i - 1] && distance[i] + distance[i - 4] >= distance[i - 2] && distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                return true;
            }
        }
        return false;
    }
}
// @lc code=end

