/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;

        while (l < r) {
            ans = std::max(ans, std::min(height[l], height[r]) * (r - l));

            // Shift the lower side each time (because the area is subject to
            // the lower side, not the higher side).
            if (height[l] < height[r])  ++l;
            else  --r;
        }
        return ans;
    }
};
// @lc code=end

