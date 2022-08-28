/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */
#include <bits/stdc++.h>

using std::greater;
using std::priority_queue;
using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {-1, 0, 1, 0, -1};

public:
    // T: O(n ^ 2 * log(n))
    // S: O(n ^ 2)
    int swimInWater(const vector<vector<int>>& grid) {
        const int n = grid.size();
        int ans = grid[n - 1][n - 1];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        min_heap.push({grid[0][0], 0, 0});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        while (min_heap.size()) {
            auto cur = min_heap.top(); min_heap.pop();  // pick the cell with minimum t
            ans = std::max(ans, cur[0]);

            for (int d = 0; d < 4; ++d) {
                int r = cur[1] + D[d], c = cur[2] + D[d + 1];
                if (r == n - 1 && c == n - 1) return ans;
                if (0 <= r && r < n && 0 <= c && c < n && !vis[r][c]) {
                    min_heap.push({grid[r][c], r, c});
                    vis[r][c] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

