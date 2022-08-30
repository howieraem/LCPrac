/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */
#include <bits/stdc++.h>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
    // Find the number of permutations (not combinations!)
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    int numberOfBoomerangs(vector<vector<int>>& points) {
        const int n = points.size();
        unordered_map<int, int> dist_cnts;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // no need to skip i == j here because n * (n - 1) below will handle this case
                ++dist_cnts[dist(points[i], points[j])];
            }

            for (const auto& p : dist_cnts) {
                // nP2 = n! / (n - 2)! = n * (n - 1)
                ans += p.second * (p.second - 1);
            }

            dist_cnts.clear();
        }
        return ans;
    }

private:
    int dist(const vector<int>& a, const vector<int>& b) {
        int dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};
// @lc code=end

