/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */
#include <bits/stdc++.h>

using std::pair;
using std::queue;
using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {1, 0, -1, 0, 1};

public:
    // Start search from the rotten oranges.

    // BFS-based
    // T: O(m * n)
    // S: O(m * n)
    int orangesRotting(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int n_fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
                n_fresh += (grid[i][j] == 1);
            }
        }

        int ans = 0;
        // IMPORTANT: this loop covers the case where there is 0 fresh orange initially, 
        // and stops early by preventing the final round of level visits
        while (n_fresh != 0 && q.size() != 0) {
            ++ans;
            auto qs = q.size();
            while (qs-- > 0) {
                auto [r, c] = q.front(); q.pop();
            
                for (int d = 0; d < 4; ++d) {
                    int nr = r + D[d], nc = c + D[d + 1];
                    if (0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == 1) {
                        q.emplace(nr, nc);
                        grid[nr][nc] = 2;
                        --n_fresh;
                    }
                }
            }
        }
        return n_fresh == 0 ? ans : -1;
    }

    // DFS-based: https://leetcode.com/problems/rotting-oranges/discuss/602284/
};
// @lc code=end

