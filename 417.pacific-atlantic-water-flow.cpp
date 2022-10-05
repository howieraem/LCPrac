/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */
#include <bits/stdc++.h>

using std::queue;
using std::vector;

// @lc code=start
using pos = std::pair<int, int>;

class Solution {
    static constexpr int D[] {1, 0, -1, 0, 1};

public:
    // Idea: start search from the oceans (grid boundary cells), then check inner cells reachable from both oceans
    
    /*
    // BFS-based 
    // T: O(m * n)
    // S: O(m * n)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size(), n = heights[0].size();
        queue<pos> q_p, q_a;
        vector<vector<uint8_t>> vis_p(m, vector<uint8_t>(n, 0)), vis_a(m, vector<uint8_t>(n, 0));

        // Horizontal boundaries
        for (int i = 0; i < m; ++i) {
            q_p.emplace(i, 0);
            vis_p[i][0] = 1;
            q_a.emplace(i, n - 1);
            vis_a[i][n - 1] = 1;
        }

        // Vertical boundaries
        for (int j = 0; j < n; ++j) {
            q_p.emplace(0, j);
            vis_p[0][j] = 1;
            q_a.emplace(m - 1, j);
            vis_a[m - 1][j] = 1;
        }

        bfs(heights, q_p, vis_p, m, n);
        bfs(heights, q_a, vis_a, m, n);

        // Eligible cells should be reachable from both oceans
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis_p[i][j] && vis_a[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void bfs(const vector<vector<int>>& heights, queue<pos>& q, vector<vector<uint8_t>>& vis, const int& m, const int& n) {
        while (q.size()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nr = r + D[d], nc = c + D[d + 1];
                if (0 <= nr && nr < m && 0 <= nc && nc < n && !vis[nr][nc] && 
                    heights[nr][nc] >= heights[r][c]) {   // IMPORTANT: can go forward if next height is greater or equal, as it travels from ocean to inner cells
                    q.emplace(nr, nc);
                    vis[nr][nc] = 1;
                }
            }
        }
    }
    */

    // DFS-based
    // T: O(m * n)
    // S: O(m * n)
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int m = heights.size(), n = heights[0].size();
        vector<vector<uint8_t>> vis_p(m, vector<uint8_t>(n, 0)), vis_a(m, vector<uint8_t>(n, 0));
        
        // Horizontal boundaries
        for (int i = 0; i < m; ++i) {
            if (!vis_p[i][0]) {
                vis_p[i][0] = 1;
                dfs(heights, vis_p, i, 0, m, n);
            }
            
            if (!vis_a[i][n - 1]) {
                vis_a[i][n - 1] = 1;
                dfs(heights, vis_a, i, n - 1, m, n);
            }
        }

        // Vertical boundaries
        for (int j = 0; j < n; ++j) {
            if (!vis_p[0][j]) {
                vis_p[0][j] = 1;
                dfs(heights, vis_p, 0, j, m, n);
            }
            
            if (!vis_a[m - 1][j]) {
                vis_a[m - 1][j] = 1;
                dfs(heights, vis_a, m - 1, j, m, n);
            }
        }

        // Eligible cells should be reachable from both oceans
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis_p[i][j] && vis_a[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& heights, vector<vector<uint8_t>>& vis, int r, int c, const int& m, const int& n) {
        for (int d = 0; d < 4; ++d) {
            int nr = r + D[d], nc = c + D[d + 1];
            if (0 <= nr && nr < m && 0 <= nc && nc < n && !vis[nr][nc] && 
                heights[nr][nc] >= heights[r][c]) {  // IMPORTANT: can go forward if next height is greater or equal, as it travels from ocean to inner cells
                vis[nr][nc] = 1;
                dfs(heights, vis, nr, nc, m, n);
            }
        }
    }
};
// @lc code=end

