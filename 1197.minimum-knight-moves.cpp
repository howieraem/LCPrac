/*
 * @lc app=leetcode id=1197 lang=cpp
 *
 * [1197] Minimum Knight Moves
 */
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
    static constexpr int D[6][2] {
        {1, 2},
        {2, 1},
        {1, -2},
        {-2, 1},
        {-1, 2},
        {2, -1}
    };

public:
    /*
    // Possible movements are symmetric, so most negative coordinates can be ignored, 
    // except x = -1 or y = -1. For example, to reach (1, 1) from (0, 0), the best way 
    // is to get (2, -1) or (-1, 2) first, then (1, 1) (two steps).
    // Meanwhile, directions (-1, -2) and (-2, -1) can be ignored.
    // T: O(abs(x) * abs(y))
    // S: O(abs(x) * abs(y))
    int minKnightMoves(int x, int y) {
        if (!x && !y)  return 0;

        x = abs(x);
        y = abs(y);

        int steps = 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        unordered_set<string> vis;
        vis.insert("0,0");

        while (q.size()) {
            int qs = q.size();
            while (qs--) {
                auto p = q.front(); q.pop();
                for (int d = 0; d < 6; ++d) {
                    int nx = p.first + D[d][0], ny = p.second + D[d][1];
                    if (nx == x && ny == y)  return steps + 1;
                    if (nx >= -1 && nx <= x + 2 && ny >= -1 && ny <= y + 2) {   // prune
                        string key = to_string(nx) + "," + to_string(ny);
                        if (vis.find(key) == vis.end()) {
                            q.emplace(nx, ny);
                            vis.insert(key);
                        }
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
    */

    // DFS with memo. Opposite simulation: minimum steps to move from (x, y) to (0, 0).
    // T: O(abs(x) * abs(y))
    // S: O(abs(x) * abs(y))
    int minKnightMoves(int x, int y) {
        // base cases when x <= 2 or y <= 2
        unordered_map<string, int> memo = { 
            {"0,0", 0},
            {"0,1", 3},
            {"0,2", 2},
            {"1,1", 2},
            {"1,2", 1},
            {"2,2", 4}
        };
        return dfs(abs(x), abs(y), memo);
    }

private:
    static int dfs(int x, int y, unordered_map<string, int> &memo) {
        if (x > y)  swap(x, y);     // Because of symmetry, always make y larger to reduce search space
        string key = to_string(x) + "," + to_string(y);
        if (memo.find(key) != memo.end())  return memo[key];
        int ans = min(dfs(abs(x - 2), abs(y - 1), memo), dfs(abs(x - 1), abs(y - 2), memo)) + 1;
        memo[key] = ans;
        return ans;
    }
};
// @lc code=end

