/*
 * @lc app=leetcode id=755 lang=cpp
 *
 * [755] Pour Water
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(volume + len(heights))
    // S: O(1)
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int j = k;
        while (volume-- > 0) {
            while (j > 0 && heights[j] >= heights[j - 1]) {
                // If the droplet would eventually fall by moving left, then move left
                --j;
            }
            while (j < heights.size() - 1 && heights[j] >= heights[j + 1]) {
                // Otherwise, if the droplet would eventually fall by moving right, then move right
                ++j;
            }
            while (j > k && heights[j] == heights[j - 1]) {
                // Otherwise, rise to its current position
                --j;
            }
            ++heights[j];
        }
        return heights;
    }
};
// @lc code=end

