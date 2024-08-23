/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    const vector<int> dirn {0, -1, 0, 1, 0};

    void dfs(vector<vector<int>>& grid, int i, int j, const int& m, const int& n) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;  // mark visited
        for (int k = 0; k < 4; ++k) {
            dfs(grid, i + dirn[k], j + dirn[k + 1], m, n);
        }
    }

public:
    // T: O(m * n), m := len(grid), n := len(grid[0])
    // S: O(m * n)
    int regionsBySlashes(vector<string>& grid) {
        // Convert strings to an upsampled grid and mark boundaries
        const int m = grid.size();
        if (m == 0)  return 0;
        const int n = grid[0].size();
        // a factor of 3 is the minimum to separate parallel boundaries, e.g. ["//", "/ "]
        const int K = 3;
        vector<vector<int>> g(m * K, vector<int>(n * K));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    g[i * K][j * K + 2] = 1;
                    g[i * K + 1][j * K + 1] = 1;
                    g[i * K + 2][j * K] = 1;
                } else if (grid[i][j] == '\\') {
                    g[i * K][j * K] = 1;
                    g[i * K + 1][j * K + 1] = 1;
                    g[i * K + 2][j * K + 2] = 1;
                } // else do nothing for space char
            }
        }

        // Do DFS to find the "islands" (grid will be modified in-place to mark visited)
        int ans = 0;
        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[0].size(); ++j) {
                if (g[i][j] == 0) {
                    dfs(g, i, j, g.size(), g[0].size());
                    ++ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

