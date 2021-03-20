/*
 * @lc app=leetcode.cn id=1011 lang=java
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
    public int shipWithinDays(int[] weights, int D) {
        // 二分搜索，找最左边的目标值
        int l = getMax(weights);        // mininum possible cap
        int r = getSum(weights) + 1;    // maximum possible cap, add 1 to search for the leftmost item
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (canFinish(weights, D, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean canFinish(int[] weights, int D, int cap) {
        int i = 0;
        for (int day = 0; day < D; ++day) {
            int maxCap = cap;
            while ((maxCap -= weights[i]) >= 0) {
                ++i;
                if (i == weights.length)  return true;
            }
        }
        return false;
    }

    private int getMax(int[] arr) {
        int ans = Integer.MIN_VALUE;
        for (int n : arr) {
            ans = Math.max(ans, n);
        }
        return ans;
    }

    private int getSum(int[] arr) {
        int ans = 0;
        for (int n : arr) {
            ans += n;
        }
        return ans;
    }
}
// @lc code=end

