/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <vector>

// @lc code=start
class Solution {
public:
    // Idea: sum water amount of each bin (width = 1).
    // T: O(n)
    // S: O(1)
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1, maxL = 0, maxR = 0;
        while (l <= r) {
            // if (height[l] < height[r]) {
            if (maxL < maxR) {
                if (height[l] > maxL)  maxL = height[l];
                else  ans += maxL - height[l];
                ++l;
            } else {
                if (height[r] > maxR)  maxR = height[r];
                else  ans += maxR - height[r];
                --r;
            }
        }
        return ans;
    }
};
// @lc code=end

