/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {1, 0, -1, 0, 1};

public:
    /*
    // BFS
    // T: O(m * n)
    // S: O(m * n)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (sr >= image.size() || sc >= image[sr].size()) {
            return image;
        }
        int pre_color = image[sr][sc];
        if (pre_color == color) {
            return image;
        }
        std::queue<std::pair<int, int>> q;
        q.emplace(sr, sc);
        while (!q.empty()) {
            int qs = q.size();
            while (qs-- > 0) {
                auto [r, c] = q.front(); q.pop();
                image[r][c] = color;

                for (int d = 0; d < 4; ++d) {
                    int nr = r + D[d];
                    int nc = c + D[d + 1];

                    if (0 <= nr && nr < image.size() && 0 <= nc && nc < image[nr].size() && image[nr][nc] == pre_color) {
                        q.emplace(nr, nc);
                    }
                }
            }
        }
        return image;
    }
    */
    
    // DFS
    // T: O(m * n)
    // S: O(m * n)
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (sr >= image.size() || sc >= image[sr].size()) {
            return image;
        }
        int pre_color = image[sr][sc];
        if (pre_color == color) {
            return image;
        }
        dfs(image, sr, sc, pre_color, color);
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int r, int c, const int& pre_color, const int color) {
        image[r][c] = color;
        for (int d = 0; d < 4; ++d) {
            int nr = r + D[d];
            int nc = c + D[d + 1];

            if (0 <= nr && nr < image.size() && 0 <= nc && nc < image[nr].size() && image[nr][nc] == pre_color) {
                dfs(image, nr, nc, pre_color, color);
            }
        }
    }
};
// @lc code=end

