/*
 * @lc app=leetcode.cn id=1011 lang=java
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int min = Integer.MAX_VALUE, sum = 0;
        for (int w : weights) {
            min = Math.min(min, w);
            sum += w;
        }
        int l = min, r = sum + 1;
        // Find lower bound (min. capacity required)
        while (l < r) {
            int m = l + ((r - l) >> 1);
            if (canFinish(weights, D, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    private boolean canFinish(int[] weights, int D, int maxCap) {
        int i = 0;
        for (int day = 0; day < D; ++day) {
            int cap = maxCap;
            while ((cap -= weights[i]) >= 0) {
                ++i;
                if (i == weights.length)  return true;
            }
        }
        return false;
    }

    // private int getMax(int[] arr) {
    //     int ans = Integer.MIN_VALUE;
    //     for (int n : arr) {
    //         ans = Math.max(ans, n);
    //     }
    //     return ans;
    // }

    // private int getSum(int[] arr) {
    //     int ans = 0;
    //     for (int n : arr) {
    //         ans += n;
    //     }
    //     return ans;
    // }
}
// @lc code=end

