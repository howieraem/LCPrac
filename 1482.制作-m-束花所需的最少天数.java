/*
 * @lc app=leetcode.cn id=1482 lang=java
 *
 * [1482] 制作 m 束花所需的最少天数
 */

// @lc code=start
class Solution {
    /**
     * 假设「所需的最少天数」为 ans ，那么以 ans 为分割点的数轴具有「二段性」：
     *  - 天数范围落在 [0, ans) 无法制作完成
     *  - 天数范围在 [ans, +∞) 可以制作完成
     */
    public int minDays(int[] bloomDay, int m, int k) {
        if (m > bloomDay.length / k)  return -1;
        int low = Integer.MAX_VALUE, high = 0;
        for (int bd : bloomDay) {
            low = Math.min(low, bd);
            high = Math.max(high, bd);
        }

        // 二分，找最左边的答案
        while (low < high) {
            int days = low + (high - low) / 2;
            if (validate(bloomDay, days, m, k)) {
                high = days;
            } else {
                low = days + 1;
            }
        }
        return low; 
    }

    private boolean validate(int[] bloomDay, int days, int m, int k) {
        int bouquets = 0, flowers = 0; 
        int i = 0, n = bloomDay.length;
        while (i < n && bouquets < m) {
            if (bloomDay[i] <= days) {
                ++flowers;
                if (flowers == k) {
                    ++bouquets;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            ++i;
        }
        return bouquets >= m;
    }
}
// @lc code=end

