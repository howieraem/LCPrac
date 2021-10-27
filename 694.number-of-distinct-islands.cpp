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
public:
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
                    string sb;
                    if (dfs(grid, i, j, sb, 'o')) {
                        grid[i][j] = 0;
                        islands.insert(sb);
                    }
                }
            }
        }
        return islands.size();
    }

private:
    /**
     * Returns true if the island is new.
     */
    static bool dfs(vector<vector<int>>& grid, int i, int j, string& sb, char dirn) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[i].size() || !grid[i][j]) {
            return false;
        }
        sb.push_back(dirn);
        grid[i][j] = 0;
        dfs(grid, i - 1, j, sb, 'u');
        dfs(grid, i + 1, j, sb, 'd');
        dfs(grid, i, j - 1, sb, 'l');
        dfs(grid, i, j + 1, sb, 'r');
        sb.push_back('b');
        return true;
    }
};
// @lc code=end

