/*
 * @lc app=leetcode id=286 lang=cpp
 *
 * [286] Walls and Gates
 */
#include <bits/stdc++.h>

using std::pair;
using std::queue;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {1, 0, -1, 0, 1};

public:
    // Start search from gates, and fill in distance values during BFS
    // T: O(m * n)
    // S: O(m * n)
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;

        // Queue all gates
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }

        // Search and fill in distance values
        while (q.size()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nr = r + D[d], nc = c + D[d + 1];
                // As BFS guarantees that closer cells are visited first, only need to check once whether a room has been visited.
                // No need to update the distance of the same room cell multiple times.
                if (0 <= nr && nr < m && 0 <= nc && nc < n && rooms[nr][nc] == INT_MAX) {
                    rooms[nr][nc] = rooms[r][c] + 1;  // IMPORTANT: if a gate is at (r, c), then rooms[r][c] = 0 as predefined, so this works
                    q.emplace(nr, nc);
                }
            }
        }
    }
};
// @lc code=end

