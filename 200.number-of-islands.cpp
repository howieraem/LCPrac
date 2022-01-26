/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include <deque>
#include <vector>
#include <utility>

using std::deque;
using std::pair;
using std::vector;

// @lc code=start
class Solution {
    static constexpr int DIRN[5] = {-1, 0, 1, 0, -1};

public:
    // BFS solution
    // T: O(m * n), m := the number of rows, n := the number of columns
    // S: O(m * n)
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        deque<pair<int, int>> q;    // deque has clear() API
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    grid[i][j] = '0';   // mark visited

                    // For each island, do BFS and mark all cells of that current island visited
                    q.clear();
                    q.emplace_back(i, j);
                    while (q.size()) {
                        int qs = q.size();
                        while (qs--) {
                            const auto p = q.front(); q.pop_front();
                            for (int d = 0; d < 4; ++d) {
                                int ni = p.first + DIRN[d],
                                    nj = p.second + DIRN[d + 1];
                                if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[ni].size() && grid[ni][nj] == '1') {
                                    grid[ni][nj] = '0';
                                    q.emplace_back(ni, nj);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

    /*
    // DFS solution
    // T: O(m * n), m := the number of rows, n := the number of columns
    // S: O(m * n)
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

private:
    static void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';   // marked visited
        for (int d = 0; d < 4; ++d) {
            int ni = i + DIRN[d], nj = j + DIRN[d + 1];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[ni].size() && grid[ni][nj] == '1') {
                dfs(grid, ni, nj);
            }
        }
    }
    */
};
// @lc code=end

