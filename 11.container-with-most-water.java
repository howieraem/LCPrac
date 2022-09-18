/*
 * @lc app=leetcode id=11 lang=java
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(1)
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1, ans = 0;

        while (l < r) {
            ans = Math.max(ans, (r - l) * Math.min(height[l], height[r]));

            // Change the lower side and check if it becomes higher in the next round 
            // so that more water can be contained
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
}
// @lc code=end

