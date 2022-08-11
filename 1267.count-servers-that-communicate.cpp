/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(m + n)
    int countServers(const vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    ++rows[i], ++cols[j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Check if there are any other servers except the current one 
                // in it's corresponding row or column.
                ans += (grid[i][j] && (rows[i] > 1 || cols[j] > 1));
            }
        }
        return ans;
    }
};
// @lc code=end

