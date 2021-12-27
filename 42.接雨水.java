/*
 * @lc app=leetcode.cn id=42 lang=java
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
    public int trap(int[] height) {
        final int n = height.length;
        // if (n == 0)  return 0;
        int l = 0, r = n - 1;
        int ans = 0;
        int l_max = height[0], r_max = height[n - 1];
        while (l <= r) {
            l_max = Math.max(l_max, height[l]);
            r_max = Math.max(r_max, height[r]);
            if (l_max < r_max) {
                ans += l_max - height[l];
                ++l;
            } else {
                ans += r_max - height[r];
                --r;
            }
        }
        return ans;
    }
}
// @lc code=end

