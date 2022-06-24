/*
 * @lc app=leetcode id=1257 lang=cpp
 *
 * [1257] Smallest Common Region
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n), n := the number of regions
    // S: O(n)
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<std::string_view, std::string_view> parent;      

        for (const auto& r : regions) {
            for (int i = 1; i < r.size(); ++i) {
                parent[r[i]] = r[0];
            }
        }

        std::string_view r1(region1), r2(region2), p1 = r1, p2 = r2;
        while (p1 != p2) {
            p1 = parent.find(p1) != parent.end() ? parent[p1] : r1;
            p2 = parent.find(p2) != parent.end() ? parent[p2] : r2;
        }
        return string(p1);
    }
};
// @lc code=end

