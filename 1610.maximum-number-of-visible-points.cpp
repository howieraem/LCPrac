/*
 * @lc app=leetcode id=1610 lang=cpp
 *
 * [1610] Maximum Number of Visible Points
 */
#include <bits/stdc++.h>
#include <cmath>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int visiblePoints(const vector<vector<int>>& points, int angle, const vector<int>& location) {
        // Transform to radian space
        vector<double> point_angles;
        point_angles.reserve(points.size() << 1);
        int ox = location[0], oy = location[1];
        int extra = 0;
        for (const auto& p : points) {
            if (p[0] == ox && p[1] == oy) {
                ++extra;
            } else {
                point_angles.push_back(atan2((double)p[1] - oy, (double)p[0] - ox));
            }
        }
        std::sort(point_angles.begin(), point_angles.end());

        // Need to go around the circle, so duplicate the radians array and 
        // offset the second half by 2*pi. Special case handled: visible points 
        // in the 1st and the 4th quadrants. 
        auto n_point_angles = point_angles.size();
        for (auto i = 0; i < n_point_angles; ++i) {
            point_angles.push_back(point_angles[i] + 2 * M_PI);
        }

        // Sliding-window
        double angle_radian = M_PI * angle / 180;
        int ans = 0;
        int l = 0, r = 0;
        while (r < point_angles.size()) {
            while (point_angles[r] - point_angles[l] > angle_radian) {
                ++l;
            }
            ans = std::max(ans, r - l + 1);
            ++r;
        }
        return ans + extra;
    }
};
// @lc code=end

