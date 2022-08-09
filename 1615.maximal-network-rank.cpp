/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2)
    // S: O(n ^ 2)
    int maximalNetworkRank(int n, const vector<vector<int>>& roads) {
        vector<vector<uint8_t>> connected(n, vector<uint8_t>(n, 0));
        vector<int> cnts(n);
        for (const auto& r : roads) {
            ++cnts[r[0]];
            ++cnts[r[1]];
            connected[r[0]][r[1]] = 1;
            connected[r[1]][r[0]] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // If a road is directly connected to both cities, it is only counted once
                ans = std::max(ans, cnts[i] + cnts[j] - (connected[i][j]));
            }
        }
        return ans;
    }
};
// @lc code=end

