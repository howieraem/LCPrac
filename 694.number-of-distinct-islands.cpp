/*
 * @lc app=leetcode id=694 lang=cpp
 *
 * [694] Number of Distinct Islands
 */
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    static constexpr int D[] {0, 1, 0, -1, 0};

public:
    // Solution 1: DFS
    // T: O(m * n)
    // S: O(m * n)
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                // Since the iteration is from top to bottom and from left to right,
                // it is guaranteed that the first cell of an island encountered will
                // always be the top left corner, which can be used as a reference
                // point for other cells of the same island. A shape of an island
                // can thus be represented by a string with characters indicating 
                // DFS directions from the reference point.
                if (grid[i][j]) {
                    string island;
                    dfs(grid, i, j, island, 'o');
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }

private:
    static void dfs(vector<vector<int>> &grid, int i, int j, string &island, char dirn) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[i].size() || !grid[i][j]) {
            return;
        }
        island.push_back(dirn);
        grid[i][j] = 0;     // mark visited
        for (int d = 0; d < 4; ++d) {
            dfs(grid, i + D[d], j + D[d + 1], island, d + '0');
        }
        island.push_back('b');  // REQUIRED
    }

    /*
    // Solution 2: BFS
    // T: O(m * n)
    // S: O(m * n)
    int numDistinctIslands(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        string island;
        unordered_set<string> islands;
        const int m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    island = ",";
                    
                    while (q.size()) {
                        const auto &[r, c] = q.front();
                        for (int d = 0; d < 4; ++d) {
                            int nr = r + D[d], nc = c + D[d + 1];

                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]) {
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                                island.push_back(d + '0');
                            }
                        }
                        island.push_back(',');
                        q.pop();
                    }
                    
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
    */
};
// @lc code=end

