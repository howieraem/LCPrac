/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // mono-stack
    // T: O(n)
    // S: O(n)
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        stack<pair<int, int>> s; // Stores pairs of (index, height) in ascending order of height
        // Insert a dummy data point to make the following solution more elegant
        s.push({-1, 0});
        int ans = -1;

        for (int i = 0; i < heights.size(); ++i) {
            while (s.top().second > heights[i]) {
                const auto &[pre_i, h] = s.top(); s.pop();
                int w = (i - 1 - s.top().first);
                ans = max(ans, h * w);
            }
            s.push({i, heights[i]});
        }

        // Don't forget the last bars
        while (s.top().first != -1) {
            const auto &[i, h] = s.top(); s.pop();
            int w = (n - 1 - s.top().first);
            ans = max(ans, h * w);
        }
        return ans;
    }
};
// @lc code=end

