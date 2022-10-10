/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */
#include <bits/stdc++.h>

using std::array;
using std::greater;
using std::priority_queue;
using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {-1, 0, 1, 0, -1};

public:
    // T: O(n ^ 2 * log(n)) because log(n ^ 2) = 2log(n)
    // S: O(n ^ 2)
    // (For a more generalized solution, see the java version)
    int swimInWater(const vector<vector<int>>& grid) {
        const int n = grid.size();

        // priority queue stores tuples (grid[r][c], r, c)
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> min_heap;
        vector<vector<uint8_t>> vis(n, vector<uint8_t>(n, 0));

        min_heap.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        
        int ans = grid[n - 1][n - 1];  // the final ans must be no less than the time value of the destination cell
        while (min_heap.size()) {
            auto [t, r, c] = min_heap.top(); min_heap.pop();  // visit the cell with minimum t first
            ans = std::max(ans, t);

            for (int d = 0; d < 4; ++d) {
                int nr = r + D[d], nc = c + D[d + 1];
                if (nr == n - 1 && nc == n - 1) return ans;  // IMPORTANT: we can return here because ans is initialized to grid[-1][-1]
                if (0 <= nr && nr < n && 0 <= nc && nc < n && !vis[nr][nc]) {
                    min_heap.push({grid[nr][nc], nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

