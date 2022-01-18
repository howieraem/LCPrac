/*
 * @lc app=leetcode.cn id=746 lang=java
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int dpi_2 = 0, dpi_1 = 0;
        for (int i = 0; i < cost.length; ++i) {
            int dpi = cost[i] + Math.min(dpi_2, dpi_1);
            dpi_2 = dpi_1;
            dpi_1 = dpi;
        }
        return Math.min(dpi_2, dpi_1);
    }
}
// @lc code=end

