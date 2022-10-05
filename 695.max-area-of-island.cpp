/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {1, 0, -1, 0, 1};

public:
    /*
    // BFS-based
    // T: O(m * n)
    // S: O(m * n)
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const size_t m = grid.size(), n = grid[0].size();
        std::queue<std::pair<size_t, size_t>> q;
        int ans = 0;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int cur_area = 0;
                    q.emplace(i, j);
                    grid[i][j] = 0;

                    while (q.size()) {
                        auto [r, c] = q.front(); q.pop();
                        ++cur_area;

                        for (int d = 0; d < 4; ++d) {
                            size_t nr = r + D[d], nc = c + D[d + 1];
                            if (0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == 1) {
                                q.emplace(nr, nc);
                                grid[nr][nc] = 0;
                            }
                        }
                    }

                    ans = std::max(ans, cur_area);
                }
            }
        }
        return ans;
    }
    */

    // DFS-based
    // T: O(m * n)
    // S: O(m * n)
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const size_t m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ans = std::max(ans, dfs(grid, i, j, m, n));
                }
            }
        }
        return ans;
    }

private:
    static int dfs(vector<vector<int>>& grid, size_t r, size_t c, const size_t& m, const size_t& n) {
        int cur_area = 1;
        grid[r][c] = 0;
        for (int d = 0; d < 4; ++d) {
            size_t nr = r + D[d], nc = c + D[d + 1];
            if (0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc] == 1) {
                cur_area += dfs(grid, nr, nc, m, n);
            }
        }
        return cur_area;
    }
};
// @lc code=end

