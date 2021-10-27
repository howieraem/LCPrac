/*
 * @lc app=leetcode id=711 lang=cpp
 *
 * [711] Number of Distinct Islands II
 */
#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /** 
     * After we get coordinates for an island, compute all possible rotations/reflections 
     * (https://en.wikipedia.org/wiki/Dihedral_group) of it and then 
     * sort them using the default comparison. 
     * The first representation in this order is then the canonical one.
     */
    int numDistinctIslands2(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> set;    // using unordered_set will cause compile error
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    vector<pair<int, int>> coord;
                    dfs(grid, i, j, coord);
                    set.insert(norm(coord));
                }
            }
        }
        return set.size();
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int,int>>& coord) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[i].size() || !grid[i][j]) {
            return;
        }
        grid[i][j] = 0;
        coord.push_back({i, j});
        dfs(grid, i - 1, j, coord);
        dfs(grid, i + 1, j, coord);
        dfs(grid, i, j - 1, coord);
        dfs(grid, i, j + 1, coord);
    }

    vector<pair<int, int>> norm(vector<pair<int, int>> v) {
        // compute rotations/reflections, 8 variants
        vector<vector<pair<int, int>>> s(8);
        for (auto &p : v) {
            int x = p.first, y = p.second;
            s[0].push_back({x, y});
            s[1].push_back({x, -y});
            s[2].push_back({-x, y});
            s[3].push_back({-x, -y});
            s[4].push_back({y, -x});
            s[5].push_back({-y, x});
            s[6].push_back({-y, -x});
            s[7].push_back({y, x});
        }

        // sort
        for (auto &l : s) {
            sort(l.begin(), l.end());
        }
        for (auto &l : s) {
            for (int i = 1; i < v.size(); ++i) {
                l[i] = {l[i].first - l[0].first, l[i].second - l[0].second};
            }
            l[0] = {0, 0};
        }
        sort(s.begin(), s.end());
        return s[0];
    }
};
// @lc code=end

