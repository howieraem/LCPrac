/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
struct State {
    int keys, i, j;

    State(int _keys, int _i, int _j) {
        keys = _keys;
        i = _i;
        j = _j;
    }

    string toString() const {
        return to_string(keys) + " " + to_string(i) + " " + to_string(j);
    }
};

class Solution {
    static constexpr int DIRN[5] {-1, 0, 1, 0, -1};

public:
    // T: O(m * n * (k!)), k := the number of key-lock pairs
    // S: O(m * n)
    int shortestPathAllKeys(vector<string>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int si = -1, sj = -1, maxKey = -1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                const char &c = grid[i][j];
                if (c == '@') {
                    si = i;
                    sj = j;
                } else if (c >= 'a' && c <= 'f') {
                    maxKey = max(maxKey, c - 'a' + 1);
                    // This variable is used to construct the final state bit mask
                }
            }
        }
        const int finalKeyState = ((1 << maxKey) - 1);    // 111111, 11111, etc.

        queue<State> q;
        unordered_set<string> vis;
        State start(0, si, sj);
        q.emplace(start);
        vis.insert(start.toString());
        int ans = 0;
        while (q.size()) {
            int qs = q.size();
            while (qs--) {
                State s = q.front(); q.pop();
                if (s.keys == finalKeyState)  return ans;
                for (int d = 0; d < 4; ++d) {
                    int i = s.i + DIRN[d], j = s.j + DIRN[d + 1], keys = s.keys;
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#') {
                        const char &c = grid[i][j];
                        if (c >= 'A' && c <= 'F' && ((keys >> (c - 'A')) & 1) == 0) {
                            // lock without the corresponding key
                            continue;
                        }
                        if (c >= 'a' && c <= 'f') {
                            // key
                            keys |= (1 << (c - 'a'));
                        }
                        State ns(keys, i, j);
                        string nss = ns.toString();
                        if (vis.find(nss) == vis.end()) {
                            q.emplace(ns);
                            vis.insert(nss);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
// @lc code=end

