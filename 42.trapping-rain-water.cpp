/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Two pointers
    // Idea: sum water amount of each bin (width = 1).
    // https://image.ibb.co/d6A2ZU/IMG-0139.jpg
    // T: O(n)
    // S: O(1)
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0; 
        int r = height.size() - 1; 
        int l_max = height[l]; 
        int r_max = height[r];
        while (l <= r) {  // IMPORTANT: don't forget l == r
            // IMPORTANT: always update on the lower side, because the lower side determines 
            // the maximum volume of water that can be trapped
            // if (height[l] < height[r]) {
            if (l_max < r_max) {
                if (height[l] > l_max) {
                    l_max = height[l];
                } else {
                    ans += l_max - height[l];
                }
                ++l;
            } else {
                if (height[r] > r_max) {
                    r_max = height[r];
                } else {
                    ans += r_max - height[r];
                }
                --r;
            }
        }
        return ans;
    }
};
// @lc code=end

