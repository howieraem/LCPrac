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
        std::queue<std::pair<size_t, size_t>> q;
        int ans = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    int cur_area = 0;
                    q.emplace(i, j);
                    grid[i][j] = 0;  // mark visited

                    while (q.size()) {
                        auto [r, c] = q.front(); q.pop();
                        ++cur_area;

                        for (int d = 0; d < 4; ++d) {
                            size_t nr = r + D[d], nc = c + D[d + 1];
                            if (0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[nr].size() && grid[nr][nc] == 1) {
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
        int ans = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    int cur_area = 0;
                    dfs(grid, i, j, cur_area);
                    ans = std::max(ans, cur_area);
                }
            }
        }
        return ans;
    }

private:
    static void dfs(vector<vector<int>>& grid, size_t r, size_t c, int& cur_area) {
        ++cur_area;
        grid[r][c] = 0;  // mark visited
        for (int d = 0; d < 4; ++d) {
            size_t nr = r + D[d], nc = c + D[d + 1];
            if (0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[nr].size() && grid[nr][nc] == 1) {
                dfs(grid, nr, nc, cur_area);
            }
        }
    }
};
// @lc code=end

