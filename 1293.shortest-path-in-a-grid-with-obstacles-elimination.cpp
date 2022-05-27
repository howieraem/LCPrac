/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */
#include <bits/stdc++.h>

// @lc code=start
#define NOT_VIS -1

class Solution {
public:
    // T: O(m * n * k)
    // S: O(m * n * k)
    int shortestPath(std::vector<std::vector<int>>& grid, int k) {
        const int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> vis(m, std::vector<int>(n, NOT_VIS));
        std::queue<std::vector<int>> q;

        q.push({0, 0, 0, k});
        while (q.size()) {
            auto state = q.front();
            int x = state[0], y = state[1], dist = state[2], obs_remove = state[3];
            q.pop();

            if (x == m - 1 && y == n - 1)  return dist;  // destination reached
            if (x < 0 || x >= m || y < 0 || y >= n)  continue;

            if (grid[x][y] == 1) {
                if (obs_remove) {
                    // can remove the current obstacle
                    --obs_remove;
                } else {
                    // not reacheable
                    continue;
                }
            }

            if (vis[x][y] != NOT_VIS && vis[x][y] >= obs_remove) {
                // The cell has been visited, and it has already reached this cell via
                // some prev. path by removing lesser obstacles in that prev. path
                continue;
            }
            vis[x][y] = obs_remove;

            ++dist;
            q.push({x + 1, y, dist, obs_remove});
            q.push({x, y + 1, dist, obs_remove});
            q.push({x - 1, y, dist, obs_remove});
            q.push({x, y - 1, dist, obs_remove});
        }

        return -1;
    }
};
// @lc code=end

