/*
 * @lc app=leetcode id=499 lang=cpp
 *
 * [499] The Maze III
 */
#include <queue>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// @lc code=start
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        const int m = maze.size(), n = maze[0].size();
        const vector<tuple<int, int, char>> D = {{0, 1, 'r'}, {0, -1, 'l'}, {1, 0, 'd'}, {-1, 0, 'u'}};

        // this also help checking if a cell is visited
        vector<vector<pair<int, string>>> dist(m, vector<pair<int, string>>(n, make_pair(INT_MAX, "")));

        queue<tuple<int, int, int, string>> q;
        q.push({start[0], start[1], 0, ""});
        string res = "impossible";

        while (q.size()) {
            int qs = q.size();

            while (qs--) {
                auto [i, j, d, path] = q.front(); q.pop();

                // Operations below must be done here rather than at queue push
                pair<int, string> dist_and_path = make_pair(d, path);
                if (dist[i][j] <= dist_and_path)  continue;
                dist[i][j] = dist_and_path;
                if (i == dest[0] && j == dest[1]) {
                    res = path;
                }

                for (const auto [di, dj, dir] : D) {
                    int cur_i = i, cur_j = j, ni, nj;
                    while (true) {
                        ni = cur_i + di, nj = cur_j + dj;
                        if (ni < 0 || ni >= m || 
                            nj < 0 || nj >= n || 
                            maze[ni][nj]) {
                            // out of bound
                            break;
                        }
                        cur_i = ni;
                        cur_j = nj;
                        if (cur_i == dest[0] && cur_j == dest[1])  break;
                    }

                    int newDist = d + abs(i - cur_i) + abs(j - cur_j);
                    string newPath = path + dir;

                    if (dist[cur_i][cur_j] > make_pair(newDist, newPath)) {
                        q.push({cur_i, cur_j, newDist, newPath});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

